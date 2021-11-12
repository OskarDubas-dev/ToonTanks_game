// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"



void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(IsInTankRange){
		RotateTurret(Tank->GetActorLocation());
	}
	

}

void ATurret::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATurret::CheckFireCondition, FireRate, true);
}

void ATurret::CheckFireCondition()
{
	if (IsInTankRange) {
		Fire();
	}
}


bool ATurret::IsInTankRange()
{
	if (Tank)
	{
		// Find the distance to the tank
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

		// Check to see if the Tank is in range
		if (Distance < FireRange)
		{
			return true;
		}
	}
	return false;
}
