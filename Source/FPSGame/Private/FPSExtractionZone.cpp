// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSExtractionZone.h"
#include "Components/BoxComponent.h"

// Sets default values
AFPSExtractionZone::AFPSExtractionZone()
{

	OverlapComponet = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComponet->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComponet->SetCollisionResponseToAllChannels(ECR_Ignore);
	OverlapComponet->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapComponet->SetBoxExtent(FVector(200.0f));
	RootComponent = OverlapComponet;

	OverlapComponet->SetHiddenInGame(false);

	OverlapComponet->OnComponentBeginOverlap.AddDynamic(this, &AFPSExtractionZone::HandleOverlap);

}


void AFPSExtractionZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlaping With Extraction Zone!"));

}


