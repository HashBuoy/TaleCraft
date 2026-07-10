// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SphereComponent.h"
#include "TCPlayerInteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TALECRAFT_API UTCPlayerInteractionComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UTCPlayerInteractionComponent();

	virtual void BeginPlay() override;

	AActor* GetCurrentInteractable() const;

	void Initialize(USphereComponent* SphereComponent);
protected:

	UFUNCTION()
	void OnBeginOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

private:

	UPROPERTY()
	TArray<TWeakObjectPtr<AActor>> NearbyInteractables;

	
};