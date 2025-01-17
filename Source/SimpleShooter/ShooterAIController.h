// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* _behaviorTree;

	FVector _startLocation;
	FVector _playerLocation;
	FVector _lastKnownPlayerLocation;
	UBlackboardComponent* _blackboard;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	APawn* _player;

	virtual void BeginPlay() override;
};
