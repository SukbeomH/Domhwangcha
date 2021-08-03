// Fill out your copyright notice in the Description page of Project Settings.


#include "DHCPlayerState.h"
#include "DHCSaveGame.h"

ADHCPlayerState::ADHCPlayerState()
{
	AverageChaseTime = 0.0f;
	AverageEvadeTime = 0.0f;
	WinNum = 0;
	DefeatedNum = 0;

}

float ADHCPlayerState::RenewAverageChaseTime()
{
	SavePlayerData();
	return 0.0f;
}

float ADHCPlayerState::RenewAverageEvadeTime()
{
	SavePlayerData();
	return 0.0f;
}

int32 ADHCPlayerState::GetWinNum() const
{
	return WinNum;
}

int32 ADHCPlayerState::GetDefeatedNum() const
{
	return DefeatedNum;
}

float ADHCPlayerState::GetAverageChaseTime() const
{
	return AverageChaseTime;
}

float ADHCPlayerState::GetAverageEvadeTime() const
{
	return AverageEvadeTime;
}

void ADHCPlayerState::InitPlayerData()
{
	auto DHCSaveGame = Cast<UDHCSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
	if (nullptr == DHCSaveGame)
	{
		DHCSaveGame = GetMutableDefault<UDHCSaveGame>();
	}

	WinNum = DHCSaveGame->WinNum;
	DefeatedNum = DHCSaveGame->DefeatedNum;
	AverageChaseTime = DHCSaveGame->AverageChaseTime;
	AverageEvadeTime = DHCSaveGame->AverageEvadeTime;


}

void ADHCPlayerState::SavePlayerData()
{
	UDHCSaveGame* NewPlayerData = NewObject<UDHCSaveGame>();
	NewPlayerData->AverageChaseTime = AverageChaseTime;
	NewPlayerData->AverageEvadeTime = AverageEvadeTime;
	NewPlayerData->WinNum = WinNum;
	NewPlayerData->DefeatedNum = DefeatedNum;

	if (!UGameplayStatics::SaveGameToSlot(NewPlayerData, SaveSlotName, 0))
	{
		DHCLOG(Error, TEXT("SaveGame Error!"));
	}
}