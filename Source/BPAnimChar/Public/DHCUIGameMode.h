// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BPAnimChar.h"
#include "GameFramework/GameModeBase.h"
#include "DHCUIGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BPANIMCHAR_API ADHCUIGameMode : public AGameModeBase
{

	GENERATED_BODY()

private:
	ADHCUIGameMode();

	UPROPERTY()
		TSubclassOf<class APawn> PawnClass;

	UPROPERTY()
		TSubclassOf<class ADHCUIPlayerController> UIPlayerControllerClass;

public: 
	/*
	UFUNCTION(BlueprintCallable, Category = "UMG_Game") 
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass); 
	*/
protected: 
	virtual void BeginPlay() override; 
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
		TSubclassOf<UUserWidget> StartingWidgetClass; 
	
	UPROPERTY() 
		UUserWidget* CurrentWidget;

	// 게임을 시작하면 UI 인스턴스를 생성하고, 이를 뷰포트에 띄운 후에 입력은 UI에만 전달되도록 제작
	UPROPERTY()
		class UUserWidget* TitleUI;

	UPROPERTY()
		class UUserWidget* LoginUI;

	UPROPERTY()
		class UUserWidget* MatchingUI;

	UPROPERTY()
		class UUserWidget* SelectUI;

	UPROPERTY()
		class UUserWidget* RPSUI;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State", meta = (AllowPrivateAccess = true))
		EGameState mState = EGameState::TITLE;

};
