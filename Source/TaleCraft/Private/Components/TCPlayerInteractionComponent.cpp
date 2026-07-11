// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TCPlayerInteractionComponent.h"

#include "Interface/TCInteractableInterface.h"

UTCPlayerInteractionComponent::UTCPlayerInteractionComponent()
{
}

void UTCPlayerInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
}

AActor* UTCPlayerInteractionComponent::GetCurrentInteractable() const
{
	if(NearbyInteractables.IsEmpty())
	{
		return nullptr;
	}

	if(AActor* LatestInteractable = NearbyInteractables.Last().Get())
	{
		return LatestInteractable;
	}
	
	return nullptr;
}

void UTCPlayerInteractionComponent::Initialize(USphereComponent* SphereComponent)
{
	if (!IsValid(SphereComponent))
	{
		return;
	}

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnEndOverlap);
}

void UTCPlayerInteractionComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor)
	{
		return;
	}
	
	if (!OtherActor->Implements<UTCInteractableInterface>())
	{
		return;
	}
	
	NearbyInteractables.AddUnique(OtherActor);

	const FGameplayTag InteractionTag = ITCInteractableInterface::Execute_GetInteractionTag(OtherActor);
	OnInteractableChanged.Broadcast(InteractionTag);
}

void UTCPlayerInteractionComponent::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!OtherActor)
		return;

	if (!OtherActor->Implements<UTCInteractableInterface>())
	{
		return;
	}

	NearbyInteractables.Remove(OtherActor);

	if(const AActor* CurrentInteractable = GetCurrentInteractable())
	{
		const FGameplayTag InteractionTag = ITCInteractableInterface::Execute_GetInteractionTag(CurrentInteractable);
		OnInteractableChanged.Broadcast(InteractionTag);
	}
	else
	{
		OnInteractableChanged.Broadcast(FGameplayTag());
	}
}
