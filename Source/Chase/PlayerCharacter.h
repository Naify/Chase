// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class UChaseWeaponComponent;

UCLASS()
class CHASE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	UChaseWeaponComponent* WeaponComponent;

public:	
	virtual void Tick(float DeltaTime) override;

};
