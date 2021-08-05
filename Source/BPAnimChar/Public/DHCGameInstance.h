// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BPAnimChar.h"
#include "Engine/GameInstance.h"
#include "DHCGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BPANIMCHAR_API UDHCGameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public:
	UDHCGameInstance();

	virtual void Init() override;
};
