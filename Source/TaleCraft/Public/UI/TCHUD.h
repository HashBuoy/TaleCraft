// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/HUD.h"
#include "TCHUD.generated.h"

class USUDSDialogue;
/**
 * 
 */
UCLASS()
class TALECRAFT_API ATCHUD : public AHUD
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void ShowInteractionUI(USUDSDialogue* Dialogue);

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void StopInteraction();
};
