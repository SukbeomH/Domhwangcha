// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BPAnimChar.h"
#include "GameFramework/SaveGame.h"
#include "DHCSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class BPANIMCHAR_API UDHCSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UDHCSaveGame();

	UPROPERTY()
		int32 WinNum;

	UPROPERTY()
		int32 DefeatedNum;

	UPROPERTY()
		float AverageChaseTime;

	UPROPERTY()
		float AverageEvadeTime;

	UPROPERTY()
		FString ID;

	UPROPERTY()
		FString Password;


};
