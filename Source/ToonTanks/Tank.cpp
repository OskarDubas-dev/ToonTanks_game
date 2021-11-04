// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Tank Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	TankCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Tank Camera"));
	TankCamera->SetupAttachment(SpringArm);
	


}
