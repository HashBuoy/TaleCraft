// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CTDisplayInfoData.generated.h"

/**
 * 
 */
UCLASS()
class TALECRAFT_API UCTDisplayInfoData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TMap<FString,FText> SpeakerIdMap;
};
