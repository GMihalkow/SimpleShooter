// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

void AMyPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	this->GetWorldTimerManager().SetTimer(this->_timerHandle, this, &AMyPlayerController::RestartLevel, this->_restartDelaySeconds);
}
