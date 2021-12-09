// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTank.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AEnemyTank::AEnemyTank()
{
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));
	
}

/*void AEnemyTank::Turn(float Value)
{
	DeltaRotation.Yaw = (Value * UGameplayStatics::GetWorldDeltaSeconds(this) * TurnSpeed);
	AddActorLocalRotation(DeltaRotation, true);
}*/
