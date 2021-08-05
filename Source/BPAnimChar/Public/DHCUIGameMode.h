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
	
	UFUNCTION(BlueprintCallable, Category = "UMG_Game") 
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass); 

	UFUNCTION(BlueprintCallable, Category = "StateControl")
		EGameState GetCurrentState();

	UFUNCTION(BlueprintCallable, Category = "StateControl")
		void SetCurrentState(EGameState NewState);
	

	virtual void BeginPlay() override; 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> StartingWidgetClass; 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
		UUserWidget* CurrentWidget;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> NextWidgetClass;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State", meta = (AllowPrivateAccess = true))
		EGameState mState;

};
