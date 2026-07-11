// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SUDSScript.h"
#include "Engine/DataAsset.h"
#include "CTDialogueScriptData.generated.h"

/**
 * 
 */
UCLASS()
class TALECRAFT_API UCTDialogueScriptData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag,TObjectPtr<USUDSScript>> InteractionTagToScriptMap;
	
};
