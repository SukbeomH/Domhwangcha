// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BPAnimChar.h"
#include "GameFramework/GameStateBase.h"
#include "DHCGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class BPANIMCHAR_API ADHCGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	ADHCGameStateBase();

public:
	int32 GetTotalGameScore() const;
	void AddGameScore();

private:
	UPROPERTY(Transient)
		int32 TotalGameScore;

};
