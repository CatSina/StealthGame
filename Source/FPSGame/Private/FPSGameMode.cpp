// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FPSGameMode.h"
#include "FPSHUD.h"
#include "FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "FPSMyGameState.h"

AFPSGameMode::AFPSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_Player"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSHUD::StaticClass();

	GameStateClass = AFPSMyGameState::StaticClass();
}

void AFPSGameMode::CompleteMission(APawn* InstigatorPawn)
{
	if (InstigatorPawn)
	{
		if (FinishCameraClass)
		{
			TArray<AActor*> ReturnedActores;
			UGameplayStatics::GetAllActorsOfClass(this, FinishCameraClass, ReturnedActores);

			//change view target if any valid actor found
			if (ReturnedActores.Num() > 0)
			{
				AActor* NewViewTarget = ReturnedActores[0];

				for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; It++)
				{
					APlayerController* PC = It->Get();
					if (PC)
					{
						PC->SetViewTargetWithBlend(NewViewTarget, 0.5f, EViewTargetBlendFunction::VTBlend_Cubic);
					}
				}

				
			}
		}
		else
		{
				UE_LOG(LogTemp, Warning, TEXT("FinishCamera is nullptr. please update the GameMode class with valid subclass. cannot change view target"));
		}
	}

	AFPSMyGameState* GS = GetGameState<AFPSMyGameState>();
	if (GS)
	{
		GS->MulticastOnMissionComplete(InstigatorPawn);
	}

	OnMissionCompleted(InstigatorPawn);
}
