// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "ToonTanksPlayerController.h"
#include "Turret.h"

void AToonTanksGameMode::ActorDied(AActor* DeadActor) const
{
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		if (Tank->GetTankPlayerController())
		{
			ToonTanksPlayerController->SetPlayerEnabledState(false);
		}
	}
	else if (ATurret* DestroyedTurret = Cast<ATurret>(DeadActor))
	{
		DestroyedTurret->HandleDestruction();
	}
}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();
	HandleGameStart();
}

/**
 * @brief Function called at the beginning of the game.
 *
 * It switch off player controller for a
 * specific amount of time using TimerManager.SetTimer()
 */
void AToonTanksGameMode::HandleGameStart()
{
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	ToonTanksPlayerController = Cast<AToonTanksPlayerController>((UGameplayStatics::GetPlayerController(this, 0)));

	StartGame();
	
	if (ToonTanksPlayerController)
	{
		ToonTanksPlayerController->SetPlayerEnabledState(false);

		FTimerHandle PlayerEnableTimerHandle;
		FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(
			ToonTanksPlayerController,
			&AToonTanksPlayerController::SetPlayerEnabledState,
			true);
		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle,
			PlayerEnableTimerDelegate,
			StartDelay,
			false);
		
	}
}
