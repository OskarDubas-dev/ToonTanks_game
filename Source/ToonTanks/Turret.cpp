// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"



void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Find the distance to the tank
	if(Tank)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
	}
	// Check to see if the Tank is in range

	//If in range, rotate turret towards Tank

	//If visible fire rockets
}

void ATurret::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

