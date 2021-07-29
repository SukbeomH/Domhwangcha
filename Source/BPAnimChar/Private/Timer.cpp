// Fill out your copyright notice in the Description page of Project Settings.


#include "Timer.h"
#include <Components/TextBlock.h>
#include "DHCUIGamemode.h"

void UTimer::NativeConstruct()
{
	auto GameMode = Cast<ADHCUIGameMode>(GetWorld()->GetAuthGameMode());
	CurrentGameState = GameMode->GetCurrentState();
	DHCLOG(Warning, TEXT("CurrentState : %d"), CurrentGameState);

	if (CurrentGameState == EGameState::SELECT)
	{
		// 다음 화면인 SELECT의 시간 제한 설정
		DHCLOG(Warning, TEXT("CurrentState : %d"), CurrentGameState);
		CountdownTime = 15;
	}
	else if (CurrentGameState == EGameState::RPS)
	{
		// 다음 화면인 RPS의 시간 제한 설정
		DHCLOG(Warning, TEXT("CurrentState : %d"), CurrentGameState);
		CountdownTime = 3;
	}
	else if (CurrentGameState == EGameState::EVADERLOCATION)
	{
		// 다음 화면인 EVADERLOCATIONSELECT의 시간 제한 설정
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
		
	}
}
