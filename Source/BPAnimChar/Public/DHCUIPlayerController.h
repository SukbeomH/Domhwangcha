// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BPAnimChar.h"
#include "GameFramework/PlayerController.h"
#include "DHCUIPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BPANIMCHAR_API ADHCUIPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
	
};
