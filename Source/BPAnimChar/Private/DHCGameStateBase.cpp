// Fill out your copyright notice in the Description page of Project Settings.


#include "DHCGameStateBase.h"

ADHCGameStateBase::ADHCGameStateBase()
{
	TotalGameScore = 0;
}

int32 ADHCGameStateBase::GetTotalGameScore() const
{
	return TotalGameScore;
}

void ADHCGameStateBase::AddGameScore()
{
	TotalGameScore++;
}