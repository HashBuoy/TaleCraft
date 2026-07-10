// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "TCInteractableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTCInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TALECRAFT_API ITCInteractableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	/** Optional icon/tag category */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FGameplayTag GetInteractionTag() const;
};
