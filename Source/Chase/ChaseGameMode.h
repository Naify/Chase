// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ChaseGameMode.generated.h"

class AAIController;

USTRUCT(BlueprintType)
struct FGameSettings
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ChaseGame", meta=(ClampMin = 10.0, ClampMax = 50000.0))
	float PlayersSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ChaseGame", meta=(ClampMin = 10.0, ClampMax = 50000.0))
	float NPCSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ChaseGame", meta=(ClampMin = 0, ClampMax = 10))
	int32 NPCNumberToSpawn;

	//remember range in behavior tree in moveto chasing. default is 500 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ChaseGame", meta=(ClampMin = 500.0, ClampMax = 10000.0))
	float PlayerShotDistance;

	//default npc health is 100
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ChaseGame", meta=(ClampMin = 1.0, ClampMax = 10000.0))
	float PlayerShotDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ChaseGame", meta=(ClampMin = 10.0, ClampMax = 10000.0))
	float NPCMaxHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ChaseGame")
	bool RandomTarget;
};

UCLASS(minimalapi)
class AChaseGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AChaseGameMode();

	virtual void StartPlay() override;
	
protected:

	UPROPERTY(EditDefaultsOnly, Category= "Game")
	TSubclassOf<AAIController> AIControllerClass;

	UPROPERTY(EditDefaultsOnly, Category= "Game")
	TSubclassOf<APawn> AIPawnClass;
	
	UPROPERTY(EditDefaultsOnly, Category= "Game")
	FGameSettings GameSettings;

	UPROPERTY(EditDefaultsOnly, Category= "Game")
	FVector SpawnPoint = FVector(-720.0f, 540.0f, 222.0f);
	
private:
	void SpawnNPCs();
};



