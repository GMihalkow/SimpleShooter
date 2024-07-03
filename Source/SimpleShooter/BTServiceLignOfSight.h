// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTServiceLignOfSight.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UBTServiceLignOfSight : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTServiceLignOfSight();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
