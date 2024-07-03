// Fill out your copyright notice in the Description page of Project Settings.


#include "BTServiceLignOfSight.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PawnMovementComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTServiceLignOfSight::UBTServiceLignOfSight()
{
	this->NodeName = TEXT("UPDATE WHEN IN SIGHT");
}

void UBTServiceLignOfSight::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* player = UGameplayStatics::GetPlayerPawn(this, 0);

	if (player == nullptr) return;

	AAIController* controller = OwnerComp.GetAIOwner();

	if (controller->LineOfSightTo(player))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(this->GetSelectedBlackboardKey(), player->GetNavAgentLocation());
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(this->GetSelectedBlackboardKey());
	}
}
		