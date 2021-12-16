// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "ToonTanksAIController.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksAIController : public AAIController
{
	GENERATED_BODY()
private:
	UBehaviorTreeComponent* BehaviorTreeComponent;
	UBlackboardComponent* BlackboardComponent;

	//Blackboard keys
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName LocationToGoKey;

	
	/**
	 * This collection will store all the available ABotTargetPoint instances
	 * AActor is used so it is possible to call GetAllActorsOfClass()
	 */
	TArray<AActor*> BotTargetPoints;

	//THIS IS WEIRD
	//I dont like it
	//Ref of Pawn has to be named TankPawn or Im getting "  ToonTanksAIController.cpp(12): [C4458] declaration of 'Pawn' hides class member "
	virtual void OnPossess(APawn* TankPawn) override;
public:
	AToonTanksAIController();

	FORCEINLINE UBlackboardComponent* GetBlackboardComponent() const {return BlackboardComponent;}
	FORCEINLINE TArray<AActor*> GetAvailableTargetPoints() const {return BotTargetPoints;}
	
	

	
};
