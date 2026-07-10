// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/TCInteractableInterface.h"
#include "TCNPCCharacterBase.generated.h"

UCLASS()
class TALECRAFT_API ATCNPCCharacterBase : public ACharacter , public ITCInteractableInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATCNPCCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	FGameplayTag NPCTag;
};
