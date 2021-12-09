// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
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
	UFUNCTION(BlueprintImplementableEvent)
	void Turn(float Value);

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables", meta = (AllowPrivateAccess = "true"))
	float TurnSpeed = 100.0f;
	
	FVector DeltaLocation{0.0f};
	FRotator DeltaRotation{0.0f};
	UPROPERTY(VisibleAnywhere, Category = "AI")
	class UFloatingPawnMovement* FloatingPawnMovement;
	
};
