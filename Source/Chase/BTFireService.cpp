// Fill out your copyright notice in the Description page of Project Settings.


#include "BTFireService.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "ChaseWeaponComponent.h"

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
		// Blackboard->SetValueAsVector(FName("EnemyLocation"), EnemyLocation);
		HasEnemyToShoot = true;
	}	

	if (Controller)
	{
		const auto WeaponComponent = Controller->GetPawn()->FindComponentByClass<UChaseWeaponComponent>();
		if (WeaponComponent && HasEnemyToShoot)
		{
			WeaponComponent->StartFire(EnemyLocation);
		}
	}
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
