// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ChaseGameInstance.h"
#include "GameFramework/GameModeBase.h"
#include "ChaseGameMode.generated.h"

class AAIController;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Game")
	FGameSettings GameSettings;
	
	UPROPERTY(EditDefaultsOnly, Category= "Game")
	FVector SpawnPoint = FVector(-720.0f, 540.0f, 222.0f);
private:
	void SpawnNPCs();
};



