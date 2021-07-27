// Fill out your copyright notice in the Description page of Project Settings.


#include "DHCUIGameMode.h"
#include "DHCUIPlayerController.h"
#include "Blueprint/UserWidget.h"

ADHCUIGameMode::ADHCUIGameMode()
{
	DefaultPawnClass = PawnClass;
	PlayerControllerClass = UIPlayerControllerClass;
}

void ADHCUIGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (nullptr != CurrentWidget)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (nullptr != NewWidgetClass)
	{
		CurrentWidget = CreateWidget(GetWorld(), NewWidgetClass);

		if (nullptr != CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

EGameState ADHCUIGameMode::GetCurrentState()
{
	return mState;
}

void ADHCUIGameMode::SetCurrentState(EGameState NewState)
{
	mState = NewState;
}

void ADHCUIGameMode::BeginPlay()
{
	Super::BeginPlay();
	ChangeMenuWidget(StartingWidgetClass);
	
}
