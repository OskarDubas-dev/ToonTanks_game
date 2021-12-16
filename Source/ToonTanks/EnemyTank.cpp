// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTank.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AEnemyTank::AEnemyTank()
{
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));
	
}