// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"

UENUM(BlueprintType)
enum class EGameState : uint8
{
	TITLE,
	LOGIN,
	MATCHING,
	SELECT,
	RPS,
	EVADERLOCATION,
	PLAY,
	SCORE,
	GAMESET
};

DECLARE_LOG_CATEGORY_EXTERN(DHC, Log, All);
#define DHCLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define DHCLOG_S(Verbosity) UE_LOG(DHC, Verbosity, TEXT("%s"), *DHCLOG_CALLINFO)
#define DHCLOG(Verbosity, Format, ...) UE_LOG(DHC, Verbosity, TEXT("%s %s"), *DHCLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))
#define DHCCHECK(Expr, ...) {if (!(Expr)) {DHCLOG(Error, TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__;}}
