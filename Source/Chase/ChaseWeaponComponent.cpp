// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseWeaponComponent.h"
#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"
#include "Engine/World.h"

UChaseWeaponComponent::UChaseWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UChaseWeaponComponent::BeginPlay()
{
	Super::BeginPlay();	
}

void UChaseWeaponComponent::StartFire()
{
	// GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Start fire called!"));
	// UE_LOG(LogTemp, Warning, TEXT("Start fire called!"));

	MakeShot();
}

void UChaseWeaponComponent::EndFire()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("End fire called!"));
	UE_LOG(LogTemp, Warning, TEXT("End fire called!"));
}

void UChaseWeaponComponent::MakeShot()
{
	if (!GetWorld()) return;	

	USkeletalMeshComponent* Mesh = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();
	UCapsuleComponent* Capsule = GetOwner()->FindComponentByClass<UCapsuleComponent>();
	if (!Mesh || !Capsule) return;
	
	const FTransform SocketTransform = Mesh->GetSocketTransform(SocketName);

	FVector TraceStart = SocketTransform.GetLocation();
	FVector TraceEnd = TraceStart + Capsule->GetForwardVector() * TraceDistance;

	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, false, 3.0f, 0, 3.0f);


	FCollisionQueryParams CollisionPrams;
	CollisionPrams.AddIgnoredActor(GetOwner());
	FHitResult HitResult;
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility, CollisionPrams);

	if (HitResult.bBlockingHit)
	{
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 32, FColor::Red, false, 3.0f);
	}
}

