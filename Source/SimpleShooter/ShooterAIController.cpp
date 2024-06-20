// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	this->_player = UGameplayStatics::GetPlayerPawn(this, 0);

	if (_behaviorTree == nullptr) return;

	this->RunBehaviorTree(this->_behaviorTree);
	UBlackboardComponent* bb = this->GetBlackboardComponent();
	bb->SetValueAsObject(TEXT("Player"), this->_player);
}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (this->LineOfSightTo(this->_player))
	//{
	//	this->SetFocus(this->_player, EAIFocusPriority::Gameplay);
	//	this->MoveToActor(this->_player, this->_acceptanceRadius);
	//}
	//else
	//{
	//	this->ClearFocus(EAIFocusPriority::Gameplay);
	//	this->StopMovement();
	//}
}