// Copyright Epic Games, Inc. All Rights Reserved.

#include "ChaseGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "AIController.h"

AChaseGameMode::AChaseGameMode()
{

}

void AChaseGameMode::StartPlay()
{
	Super::StartPlay();

	SpawnNPCs();
}

void AChaseGameMode::SpawnNPCs()
{
	if (!GetWorld()) return;

	for (int i = 0; i < GameSettings.NPCNumberToSpawn; i++)
	{
		//set collision spawn params and spawn npcs
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		// Set initial location and rotation
		FVector SpawnLocation = FVector(-720.0f, 540.0f, 222.0f); 
		FRotator SpawnRotation = FRotator::ZeroRotator;
		
		GetWorld()->SpawnActor<APawn>(AIPawnClass, SpawnLocation, SpawnRotation, SpawnInfo);		
	}
	
}
