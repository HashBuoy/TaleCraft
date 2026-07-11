// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TCBlueprintFunctionLibrary.generated.h"

class ATCHUD;
/**
 * 
 */
UCLASS()
class TALECRAFT_API UTCBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category="TC|UI", meta=(WorldContext="WorldContextObject"))
    static ATCHUD* GetTCHUD(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Gameplay Tags")
	static FGameplayTag GameplayTagFromString(const FString& TagString);
};
