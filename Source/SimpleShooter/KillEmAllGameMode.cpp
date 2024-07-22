// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"

void AKillEmAllGameMode::PawnKilled(APawn* pawn)
{
	Super::PawnKilled(pawn);

	UE_LOG(LogTemp, Log, TEXT("%s: WAS KILLED"), *FString(pawn->GetActorNameOrLabel()));
}
