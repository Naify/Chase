// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseAIPerceptionComponent.h"
#include "AIController.h"
#include "ChaseHealthActorComponent.h"
#include "Chase/ChaseGameInstance.h"
#include "Perception/AISense_Sight.h"

void UChaseAIPerceptionComponent::BeginPlay()
{
	Super::BeginPlay();

	const auto GameInstance = GetWorld()->GetGameInstance<UChaseGameInstance>();
	if (!GameInstance) return;
	
	//Get from GameInstance because components begin play runs earlier than GameMode's
	RandomEnemy = GameInstance->GetGameSettings().ChooseRandomEnemy;
}

AActor* UChaseAIPerceptionComponent::GetClosestEnemy()
{
	TArray<AActor*> SawActors;
	GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), SawActors);

	if (SawActors.Num() == 0) return nullptr;

	const auto Controller = Cast<AAIController>(GetOwner());
	if (!Controller) return nullptr;

	const auto Pawn = Controller->GetPawn();
	if (!Pawn) return nullptr;

	float BestDistance = MAX_FLT;
	AActor* BestPawn = nullptr;

	//We can choose targets randomly or	closest
	if (RandomEnemy)
	{
		//firstly find actors with health component then choose random
		TArray<AActor*> ActorsWithHealthComponent;
		for (AActor* Actor : SawActors)
		{
			if (Actor->FindComponentByClass<UChaseHealthActorComponent>())
			{
				ActorsWithHealthComponent.Add(Actor);
			}
		}

		if (ActorsWithHealthComponent.Num() > 0)
		{
			int32 RandomIndex = FMath::RandRange(0, ActorsWithHealthComponent.Num() - 1);
			BestPawn = ActorsWithHealthComponent[RandomIndex];			
		}
	}
	else
	{
		for (auto Actor : SawActors)
		{
			//Only those with chase health will be considered
			const auto ChaseHealthActorComponent = Actor->FindComponentByClass<UChaseHealthActorComponent>();
			if (!ChaseHealthActorComponent) continue;
		
			const float Distance = (Actor->GetActorLocation() - Pawn->GetActorLocation()).Size();
			if (Distance < BestDistance)
			{
				BestDistance = Distance;
				BestPawn = Actor;
			}
		}
	}	
	
	return BestPawn;
}


