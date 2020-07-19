// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSMyGameState.h"
#include "FPSPlayerController.h"

void AFPSMyGameState::MulticastOnMissionComplete_Implementation(APawn* InstigatorPawn)
{
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; It++)
	{
		AFPSPlayerController* PC = Cast<AFPSPlayerController>(It->Get());
		if (PC && PC->IsLocalController())
		{
			PC->OnMissionCompleted(InstigatorPawn);

			// Disable Input
			APawn* MyPawn = PC->GetPawn();
			if (MyPawn)
			{
				MyPawn->DisableInput(PC);
			}
		}
	}
}
