// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	FName _moveForwardAxisName = TEXT("MoveForward");

	UPROPERTY(EditAnywhere)
	FName _moveSidewaysAxisName = TEXT("MoveSideways");

	UPROPERTY(EditAnywhere)
	FName _lookUpAxisName = TEXT("LookUp");

	UPROPERTY(EditAnywhere)
	FName _lookSidewaysAxisName = TEXT("LookSideways");

	UPROPERTY(EditAnywhere)
	FName _jumpActionKey = TEXT("Jump");

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	void MoveForward(float axis);

	void MoveSideways(float axis);

	void JumpCallback();
};
