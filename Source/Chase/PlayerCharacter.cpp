// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "ChaseWeaponComponent.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	WeaponComponent = CreateDefaultSubobject<UChaseWeaponComponent>("WeaponComponent");
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


