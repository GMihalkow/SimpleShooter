// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocation.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_PlayerLocation::UBTService_PlayerLocation()
{
	this->NodeName = TEXT("UPDATE PLAYER LOCATION");
}

void UBTService_PlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* player = UGameplayStatics::GetPlayerPawn(this, 0);

	if (player == nullptr) return;

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(this->GetSelectedBlackboardKey(), player->GetNavAgentLocation());
}