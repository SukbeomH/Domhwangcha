// Fill out your copyright notice in the Description page of Project Settings.


#include "DHCPlayerController.h"

ADHCPlayerController::ADHCPlayerController()
{
	if (EPlayerRole::CHASER == CurrentRole)
	{

	}
	else
	{
		// EVADER ����, UI ����
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
