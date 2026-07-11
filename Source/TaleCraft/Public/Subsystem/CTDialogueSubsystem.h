// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SUDSParticipant.h"
#include "Subsystems/WorldSubsystem.h"
#include "CTDialogueSubsystem.generated.h"

class UCTDialogueScriptData;
/**
 * 
 */
UCLASS(Blueprintable)
class TALECRAFT_API UCTDialogueSubsystem : public UWorldSubsystem, public ISUDSParticipant
{
	GENERATED_BODY()
	
public:
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable)
	USUDSDialogue* CreateDialogue(AActor* Interactable);
	
	UPROPERTY(EditDefaultsOnly)
	UCTDialogueScriptData* ScriptData;
};
