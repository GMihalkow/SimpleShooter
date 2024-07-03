// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "./ShooterAIController.h"
#include "./Gun.h"
#include "GameFramework/Character.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	this->NodeName = TEXT("SHOOT TASK");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	auto character = OwnerComp.GetAIOwner()->GetCharacter();

	if (character != nullptr)
	{
		for (size_t i = 0; i < character->Children.Num(); i++)
		{
			AGun* gun = Cast<AGun>(character->Children[i]);
			if (gun != nullptr)
			{
				gun->PullTrigger();
				UE_LOG(LogTemp, Log, TEXT("%s: SHOT"), *FString(gun->GetActorNameOrLabel()));
				break;
			}
		}
	}
	else
	{
		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::Succeeded;
}
