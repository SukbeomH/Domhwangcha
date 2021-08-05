// Fill out your copyright notice in the Description page of Project Settings.


#include "DHCPlayerController.h"

ADHCPlayerController::ADHCPlayerController()
{
	if (EPlayerRole::CHASER == CurrentRole)
	{

	}
	else
	{
		// EVADER 시점, UI 설정
	}
}

void ADHCPlayerController::SetCurrentPlayerRole(EPlayerRole NewRole)
{
	CurrentRole = NewRole;
}

void ADHCPlayerController::SetPreviousGameResult(EPreviousGameResult Result)
{
	PreviousGameResult = Result;
}
