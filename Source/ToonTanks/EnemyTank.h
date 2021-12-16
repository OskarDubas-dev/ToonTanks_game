// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "EnemyTank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AEnemyTank : public ABasePawn
{
	GENERATED_BODY()

	AEnemyTank();
public:
	UPROPERTY(EditAnywhere, Category = "AI")
	class UBehaviorTree* BehaviorTree;

private:
	UPROPERTY(VisibleAnywhere, Category = "AI")
	class UFloatingPawnMovement* FloatingPawnMovement;

	
	
};
