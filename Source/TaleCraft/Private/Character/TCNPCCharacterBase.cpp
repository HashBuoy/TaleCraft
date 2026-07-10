// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TCNPCCharacterBase.h"

// Sets default values
ATCNPCCharacterBase::ATCNPCCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATCNPCCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATCNPCCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATCNPCCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

