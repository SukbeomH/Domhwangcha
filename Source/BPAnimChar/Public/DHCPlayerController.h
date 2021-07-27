// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BPAnimChar.h"
#include "GameFramework/PlayerController.h"
#include "DHCPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BPANIMCHAR_API ADHCPlayerController : public APlayerController
{
	GENERATED_BODY()

	ADHCPlayerController();

	virtual void PostInitializeComponents() override;

};
