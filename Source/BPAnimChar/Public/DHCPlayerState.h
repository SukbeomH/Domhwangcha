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

	// Chase�� ����� ������ ���� ��ġ�� ����
	// Chaser���� ��� AverageChaseTime ���� �� ����
	float RenewAverageChaseTime();
	// Evader���� ��� AverageEvadeTime ���� �� ����
	float RenewAverageEvadeTime();

	int32 GetWinNum() const;
	int32 GetDefeatedNum() const;
	float GetAverageChaseTime() const;
	float GetAverageEvadeTime() const;
	FString SaveSlotName;
	
	void InitPlayerData();

	// �÷��̾ ���õ� �����Ͱ� ����� ������ �̸� �����ϵ��� ��� ����
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
