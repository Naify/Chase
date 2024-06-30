// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ChaseGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FGameSettings
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ChaseGame", meta=(ClampMin = 10.0, ClampMax = 50000.0))
	float PlayersSpeed = 600.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ChaseGame", meta=(ClampMin = 10.0, ClampMax = 50000.0))
	float NPCSpeed = 600.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ChaseGame", meta=(ClampMin = 1, ClampMax = 10))
	int32 NPCNumberToSpawn = 1;

	//remember range in behavior tree in moveto chasing. default is 500 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ChaseGame", meta=(ClampMin = 500.0, ClampMax = 10000.0))
	float PlayerShotDistance = 1000.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ChaseGame", meta=(ClampMin = 1.0, ClampMax = 10000.0))
	float PlayerShotDamage = 50.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ChaseGame", meta=(ClampMin = 10.0, ClampMax = 10000.0))
	float NPCMaxHealth = 100.0f;
};

UCLASS()
class CHASE_API UChaseGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	FName GetPlayLevelName() const { return PlayLevelName; }

	FName GetMenuLevelName() const { return MenuLevelName; }

	FGameSettings GetGameSettings() const { return GameSettings; }
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Game")
	FGameSettings GameSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Game")
	FName PlayLevelName = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Game")
	FName MenuLevelName = NAME_None;
};
