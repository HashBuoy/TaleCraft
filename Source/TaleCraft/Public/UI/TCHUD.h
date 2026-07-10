// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/HUD.h"
#include "TCHUD.generated.h"

/**
 * 
 */
UCLASS()
class TALECRAFT_API ATCHUD : public AHUD
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void ShowInteractionUI(FGameplayTag InteractionTag);

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void StopInteraction();
};
