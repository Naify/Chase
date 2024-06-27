// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseAIPerceptionComponent.h"
#include "AIController.h"
#include "ChaseHelthActorComponent.h"
#include "Perception/AISense_Sight.h"

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

	for (auto Actor : SawActors)
	{
		const auto ChaseHealthActor = Actor->FindComponentByClass<UChaseHelthActorComponent>();
		if (!ChaseHealthActor) continue;
		
		const float Distance = (Actor->GetActorLocation() - Pawn->GetActorLocation()).Size();
		if (Distance < BestDistance)
		{
			BestDistance = Distance;
			BestPawn = Actor;
		}
	}
	
	return BestPawn;
}
