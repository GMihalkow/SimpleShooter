// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* _root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* _mesh;
	
	UPROPERTY(EditAnywhere)
	UParticleSystem* _shootEffect;

	UPROPERTY(EditAnywhere)
	UParticleSystem* _hitEffect;

	UPROPERTY(EditAnywhere)
	USceneComponent* _shootSpawnPoint;

	UPROPERTY(EditAnywhere)
	float _maxRange = 1000.f;

	UPROPERTY(EditAnywhere)
	float _attackDamage = 1.f;

public:
	// Sets default values for this actor's properties
	AGun();

	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
