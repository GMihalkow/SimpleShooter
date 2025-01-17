// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/PawnMovementComponent.h"

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	this->_player = UGameplayStatics::GetPlayerPawn(this, 0);
	this->_startLocation = this->GetNavAgentLocation();

	if (_behaviorTree == nullptr) return;

	this->RunBehaviorTree(this->_behaviorTree);
	this->_blackboard = this->GetBlackboardComponent();
	this->_blackboard->SetValueAsVector(TEXT("StartLocation"), this->_startLocation);
}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}