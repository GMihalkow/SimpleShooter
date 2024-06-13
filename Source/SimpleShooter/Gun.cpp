// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"

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

