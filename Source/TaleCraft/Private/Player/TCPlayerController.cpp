// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TCPlayerController.h"

#include "EnhancedInputSubsystems.h"


void ATCPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATCPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Contexts
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}
		}
	}
}
