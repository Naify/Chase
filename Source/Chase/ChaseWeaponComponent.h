// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ChaseWeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHASE_API UChaseWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UChaseWeaponComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	FName SocketName = "Muzzle_01";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shooting")
	float TraceDistance = 1000.0f;
	
protected:
	virtual void BeginPlay() override;

public:	
	void StartFire();
	void EndFire();

	void MakeShot();
};
