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

	const bool HasEnemyToShoot = Blackboard && Blackboard->GetValueAsObject(EnemyKey.SelectedKeyName);

	if (Controller)
	{
		const auto WeaponComponent = Controller->GetPawn()->FindComponentByClass<UChaseWeaponComponent>();
		if (WeaponComponent)
		{
			HasEnemyToShoot ? WeaponComponent->StartFire() : WeaponComponent->EndFire();
		}
	}
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
