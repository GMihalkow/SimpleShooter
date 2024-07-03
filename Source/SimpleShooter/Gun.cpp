// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Engine/DamageEvents.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->_root = this->CreateDefaultSubobject<USceneComponent>(TEXT("ROOT"));
	this->SetRootComponent(this->_root);

	this->_mesh = this->CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MESH"));
	this->_mesh->AttachToComponent(this->_root, FAttachmentTransformRules::SnapToTargetIncludingScale);

	this->_shootSpawnPoint = this->CreateDefaultSubobject<USceneComponent>(TEXT("SPAWN_POINT"));
	this->_shootSpawnPoint->AttachToComponent(this->_root, FAttachmentTransformRules::SnapToTargetIncludingScale);
}

void AGun::PullTrigger()
{
	APawn* ownerPawn = Cast<APawn>(this->GetOwner());
	if (ownerPawn == nullptr) return;

	AController* ownerController = ownerPawn->GetController();
	if (ownerController == nullptr) return;

	FVector viewLocation;
	FRotator viewRotation;

	ownerController->GetPlayerViewPoint(viewLocation, viewRotation);

	FVector endLocation = viewLocation + viewRotation.Vector() * _maxRange;

	FHitResult hitResult;
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);
	params.AddIgnoredActor(this->GetOwner());

	bool hasHit = this->GetWorld()->LineTraceSingleByChannel(hitResult, viewLocation, endLocation, ECollisionChannel::ECC_GameTraceChannel1, params);

	if (hasHit)
	{
		FVector shotDir = (-viewRotation.Vector());
		FRotator shotDirRot = shotDir.Rotation();
		UGameplayStatics::SpawnEmitterAtLocation(this->GetWorld(), this->_hitEffect, hitResult.ImpactPoint, shotDirRot);
		
		AActor* hitActor = hitResult.GetActor();

		if (hitActor != nullptr)
		{
			FPointDamageEvent damageEvent = FPointDamageEvent(this->_attackDamage, hitResult, shotDir, nullptr);

			hitActor->TakeDamage(this->_attackDamage, damageEvent, ownerController, this);
		}
	}

	UE_LOG(LogTemp, Log, TEXT("SHOOTING!!!"));
	UGameplayStatics::SpawnEmitterAttached(this->_shootEffect, this->_shootSpawnPoint);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

