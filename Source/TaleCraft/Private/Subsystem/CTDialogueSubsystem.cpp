// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystem/CTDialogueSubsystem.h"

#include "SUDSDialogue.h"
#include "SUDSLibrary.h"
#include "Data/CTDialogueScriptData.h"
#include "Interface/TCInteractableInterface.h"

bool UCTDialogueSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return GetClass()->IsInBlueprint() && Super::ShouldCreateSubsystem(Outer);
}

void UCTDialogueSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

USUDSDialogue* UCTDialogueSubsystem::CreateDialogue(AActor* Interactable)
{
	if(!IsValid(Interactable))
	{
		return nullptr;
	}

	// Get the interaction tag from the interface
	const FGameplayTag InteractionTag =	ITCInteractableInterface::Execute_GetInteractionTag(Interactable);
	if (!InteractionTag.IsValid())
	{
		return nullptr;
	}

	TObjectPtr<USUDSScript>* Script = ScriptData->InteractionTagToScriptMap.Find(InteractionTag);
	if (Script == nullptr || !IsValid(*Script))
	{
		UE_LOG(LogTemp, Warning, TEXT("No dialogue script found for interaction tag %s"),*InteractionTag.ToString());
		return nullptr;
	}

	USUDSDialogue* Dialogue = USUDSLibrary::CreateDialogue(this, (*Script).Get(), false);
	Dialogue->AddParticipant(this);
	return Dialogue;

	
}
