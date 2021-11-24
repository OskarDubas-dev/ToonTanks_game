// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"
#include "DrawDebugHelpers.h"


ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Tank Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	TankCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Tank Camera"));
	TankCamera->SetupAttachment(SpringArm);
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Move"), this, &ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATank::Fire);
}


void ATank::Move(float Value)
{
	//UE_LOG(LogTemp, Warning, TEXT("Move value: %f"), Value);

	// X = Value * DeltaTime * Speed
	DeltaLocation.X = (Value * UGameplayStatics::GetWorldDeltaSeconds(this) * MoveSpeed);
	AddActorLocalOffset(DeltaLocation, true);
}

void ATank::Turn(float Value)
{
	// X = Value * DeltaTime * TurnSpeed
	DeltaRotation.Yaw = (Value * UGameplayStatics::GetWorldDeltaSeconds(this) * TurnSpeed);
	AddActorLocalRotation(DeltaRotation, true);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	TankPlayerController = Cast<APlayerController>(GetController());
}


// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (TankPlayerController)
	{
		//get results from mouse point
		FHitResult HitResult;
		TankPlayerController->GetHitResultUnderCursor(
			ECollisionChannel::ECC_Visibility,
			false,
			HitResult
		);
		//tank's turret rotate facing mouse point
		RotateTurret(HitResult.ImpactPoint);
	}
}

APlayerController* ATank::GetTankPlayerController() const
{
	return TankPlayerController;
}


void ATank::HandleDestruction()
{
	Super::HandleDestruction();
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
}
