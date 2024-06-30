// Fill out your copyright notice in the Description page of Project Settings.


#include "BTFireService.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Chase/Components/ChaseWeaponComponent.h"

UBTFireService::UBTFireService()
{
	NodeName = "Fire!";
}

void UBTFireService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	const auto Controller = OwnerComp.GetAIOwner();
	const auto Blackboard = OwnerComp.GetBlackboardComponent();

	AActor* EnemyActor = Cast<AActor>(Blackboard->GetValueAsObject(EnemyKey.SelectedKeyName));
	bool HasEnemyToShoot = false;
	FVector EnemyLocation = FVector::ZeroVector;
	if (Blackboard && EnemyActor)
	{
		EnemyLocation = EnemyActor->GetActorLocation();
		HasEnemyToShoot = true;
	}	

	if (Controller)
	{
		//checking if enemy is in range for shooting
		const auto PlayerPawn = Controller->GetPawn();
		const auto WeaponComponent = PlayerPawn->FindComponentByClass<UChaseWeaponComponent>();
		const bool IsInRange = FVector::Dist(PlayerPawn->GetActorLocation(), EnemyLocation) <= WeaponComponent->TraceDistance;

		if (WeaponComponent && HasEnemyToShoot && IsInRange)
		{
			WeaponComponent->StartFire(EnemyLocation);
		}
	}
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
