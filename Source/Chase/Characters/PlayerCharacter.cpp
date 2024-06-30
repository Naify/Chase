// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "Chase/ChaseGameInstance.h"
#include "Chase/Components/ChaseWeaponComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	WeaponComponent = CreateDefaultSubobject<UChaseWeaponComponent>("WeaponComponent");
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	const auto GameInstance = GetWorld()->GetGameInstance<UChaseGameInstance>();
	if (!GameInstance) return;
	
	GetCharacterMovement()->MaxWalkSpeed = GameInstance->GetGameSettings().PlayersSpeed;
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


