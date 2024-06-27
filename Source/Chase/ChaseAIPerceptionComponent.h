// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "ChaseAIPerceptionComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHASE_API UChaseAIPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	AActor* GetClosestEnemy();
};
