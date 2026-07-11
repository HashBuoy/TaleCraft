// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TCHUD.h"

#include "Character/TCPlayerCharacter.h"

void ATCHUD::ShowInteractionUI_Implementation(USUDSDialogue* InteractionTag)
{
}


void ATCHUD::StopInteraction_Implementation()
{
	if(ATCPlayerCharacter* PC = Cast<ATCPlayerCharacter>(GetOwningPawn()))
	{
		PC->OnStopInteraction();
	}
}

