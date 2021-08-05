// Fill out your copyright notice in the Description page of Project Settings.


#include "Timer.h"
#include <Components/TextBlock.h>
#include "DHCUIGamemode.h"

void UTimer::NativeConstruct()
{
	DHCLOG(Warning, TEXT("Constructed Timer"));

	auto GameMode = Cast<ADHCUIGameMode>(GetWorld()->GetAuthGameMode());
	CurrentGameState = GameMode->GetCurrentState();
	DHCLOG(Warning, TEXT("CurrentState : %d"), CurrentGameState);

	if (CurrentGameState == EGameState::SELECT)
	{
		DHCLOG(Warning, TEXT("CurrentState : %d"), CurrentGameState);
		CountdownTime = 15;

	}
	else if (CurrentGameState == EGameState::RPS)
	{
		DHCLOG(Warning, TEXT("CurrentState : %d"), CurrentGameState);
		CountdownTime = 3;
	}
	else if (CurrentGameState == EGameState::EVADERLOCATION)
	{
		DHCLOG(Warning, TEXT("CurrentState : %d"), CurrentGameState);
		CountdownTime = 10;
	}
	

	UpdateTimerDisplay();

	GetWorld()->GetTimerManager().SetTimer(CountdownTimerHandle, this, &UTimer::AdvancedTimer, 1.0f, true);

}

void UTimer::UpdateTimerDisplay()
{
	TxtClock->SetText(FText::AsNumber(FMath::Max(CountdownTime, 0)));
}

void UTimer::AdvancedTimer()
{
	--CountdownTime;
	DHCLOG(Warning, TEXT("CountdownTime : %d"), CountdownTime);
	UpdateTimerDisplay();
	if (CountdownTime < 1)
	{
		// 카운트다운이 완료되면 타이머를 중지
		GetWorld()->GetTimerManager().ClearTimer(CountdownTimerHandle);
		auto GameMode = Cast<ADHCUIGameMode>(GetWorld()->GetAuthGameMode());
		GameMode->ChangeMenuWidget(GameMode->NextWidgetClass);
	}
}
