// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "FPSMyGameState.generated.h"


/**
 * 
 */
UCLASS()
class FPSGAME_API AFPSMyGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	UFUNCTION(NetMulticast,Reliable)
	void MulticastOnMissionComplete(APawn* InstigatorPawn);
};
