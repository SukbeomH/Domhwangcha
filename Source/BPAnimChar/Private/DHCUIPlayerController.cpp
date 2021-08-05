// Fill out your copyright notice in the Description page of Project Settings.


#include "DHCUIPlayerController.h"
#include "Blueprint/UserWidget.h"

void ADHCUIPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeUIOnly Mode;
	// Mode.SetWidgetToFocus(TitleUI->GetCachedWidget());
	SetInputMode(Mode);
	bShowMouseCursor = true;
}
