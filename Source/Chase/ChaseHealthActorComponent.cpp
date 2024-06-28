// Fill out your copyright notice in the Description page of Project Settings.

#include "ChaseHealthActorComponent.h"
#include "GameFramework/Actor.h"

UChaseHealthActorComponent::UChaseHealthActorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UChaseHealthActorComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	OnHealthChanged.Broadcast(CurrentHealth);

	AActor* ComponentOwner = GetOwner();
	if (ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &UChaseHealthActorComponent::OnTakeAnyDamage);
	}
}

void UChaseHealthActorComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	if (IsDead()) return;
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);

	OnHealthChanged.Broadcast(CurrentHealth);
	
	if (IsDead())
	{
		OnDeath.Broadcast();
	}
}

