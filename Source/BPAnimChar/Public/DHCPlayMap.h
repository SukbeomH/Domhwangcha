// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BPAnimChar.h"
#include "GameFramework/Actor.h"
#include "DHCPlayMap.generated.h"

UCLASS()
class BPANIMCHAR_API ADHCPlayMap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADHCPlayMap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
