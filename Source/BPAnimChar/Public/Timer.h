// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BPAnimChar.h"
#include "Blueprint/UserWidget.h"
#include "Timer.generated.h"

/**
 * 
 */
UCLASS()
class BPANIMCHAR_API UTimer : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TxtClock;

	UPROPERTY(BlueprintReadWrite, Category=Timer)
		int32 CountdownTime;

	UPROPERTY(BlueprintReadWrite, Category = Timer)
		EGameState CurrentGameState;

	UPROPERTY(BlueprintReadWrite, Category = Timer)
		bool CountdownStart = 0;

	UFUNCTION(BlueprintCallable)
	void UpdateTimerDisplay();

	UFUNCTION()
	void AdvancedTimer();

	FTimerHandle CountdownTimerHandle;


};
