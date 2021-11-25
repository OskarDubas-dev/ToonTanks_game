// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	 * @brief Call to delete actor, handles the logic side of removing actor from the game.
	 * Player tank is not removed but simple hidden
	 * @param DeadActor pointer to an actor that died
	 */
	void ActorDied(AActor* DeadActor) const;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();
	
private:
	class ATank* Tank;
	class AToonTanksPlayerController* ToonTanksPlayerController;

	float StartDelay = 3.0f;
	void HandleGameStart();
};
