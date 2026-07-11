// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/TCBlueprintFunctionLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "UI/TCHUD.h"

ATCHUD* UTCBlueprintFunctionLibrary::GetTCHUD(const UObject* WorldContextObject)
{
	if (!IsValid(WorldContextObject))
	{
		return nullptr;
	}

	APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if (!IsValid(PC))
	{
		return nullptr;
	}

	return Cast<ATCHUD>(PC->GetHUD());
}

FGameplayTag UTCBlueprintFunctionLibrary::GameplayTagFromString(const FString& TagString)
{
	return FGameplayTag::RequestGameplayTag(FName(*TagString), false);
}