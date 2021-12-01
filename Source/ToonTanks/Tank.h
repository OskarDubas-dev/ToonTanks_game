// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"


/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();
	//called every frame
	virtual void Tick(float DeltaTime) override;

	bool bIsAlive = true;
	
	APlayerController* GetTankPlayerController() const;
	
	void HandleDestruction();

protected:
	void BeginPlay() override;


private:
	//Variables
	FVector DeltaLocation{0.0f};
	FRotator DeltaRotation{0.0f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables", meta = (AllowPrivateAccess = "true"))
	float TurnSpeed = 100.0f;


	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* TankCamera;


	void Move(float Value);
	void Turn(float Value);

	APlayerController* TankPlayerController;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
