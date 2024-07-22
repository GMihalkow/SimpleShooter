// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleShooterBaseGameMode.h"

void ASimpleShooterBaseGameMode::PawnKilled(APawn* pawn)
{
	APlayerController* player = Cast<APlayerController>(pawn->GetController());

	if (player == nullptr)
	{
		return;
	}

	player->GameHasEnded(nullptr, false);
}
