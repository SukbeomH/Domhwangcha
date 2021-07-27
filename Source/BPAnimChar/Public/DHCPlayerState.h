// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BPAnimChar.h"
#include "GameFramework/PlayerState.h"
#include "DHCPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class BPANIMCHAR_API ADHCPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
		ADHCPlayerState();

	// Chase가 종료될 때마다 관련 수치를 갱신
	// Chaser였을 경우 AverageChaseTime 갱신 후 저장
	float RenewAverageChaseTime();
	// Evader였을 경우 AverageEvadeTime 갱신 후 저장
	float RenewAverageEvadeTime();

	int32 GetWinNum() const;
	int32 GetDefeatedNum() const;
	float GetAverageChaseTime() const;
	float GetAverageEvadeTime() const;
	FString SaveSlotName;
	
	void InitPlayerData();

	// 플레이어에 관련된 데이터가 변경될 때마다 이를 저장하도록 기능 구현
	void SavePlayerData();

protected:

	UPROPERTY(Transient)
		float AverageChaseTime;

	UPROPERTY(Transient)
		float AverageEvadeTime;

	UPROPERTY(Transient)
		int32 WinNum;

	UPROPERTY(Transient)
		int32 DefeatedNum;


};
