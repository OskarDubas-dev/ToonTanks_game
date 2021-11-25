// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Turret.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

/**
 * Toon Tanks Custom Game Mode responsible for:
 * - destroying an actor when it's life is equal or lower than 0
 * - starting the game (with delay)
 */

UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	/**
	 * @brief Call to delete the actor, handles the logic side of removing actor from the game.
	 * Player tank is not removed but simple hidden
	 * It calls win/lose function when all enemies are dead or player is defeated.
	 * @param DeadActor pointer to an actor that died
	 */
	void ActorDied(AActor* DeadActor);

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);

private:
	class ATank* Tank;
	class AToonTanksPlayerController* ToonTanksPlayerController;


	/**
	* @brief Function called at the beginning of the game.
	*
	* It switches off player controller for a
	* specific amount of time using TimerManager.SetTimer()
	*/
	void HandleGameStart();
	float StartDelay = 3.0f;

	/**
	* @brief Called at the start of the game to find all the enemies required to beat the game
	* @return Returns the amount of turrets in game
	*/
	int32 GetTurretsTargetNumber() const;
	int32 TurretsRemaining = 0;
};
