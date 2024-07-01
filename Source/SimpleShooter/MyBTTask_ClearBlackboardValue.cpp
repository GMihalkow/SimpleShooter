// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_ClearBlackboardValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UMyBTTask_ClearBlackboardValue::UMyBTTask_ClearBlackboardValue()
{
	this->NodeName = TEXT("Clear Blackboard Value");
	UE_LOG(LogTemp, Log, TEXT("UMyBTTask_ClearBlackboardValue INSTANTIATED"));
}

EBTNodeResult::Type UMyBTTask_ClearBlackboardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

	return EBTNodeResult::Succeeded;
}