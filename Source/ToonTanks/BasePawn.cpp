// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Projectile.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ABasePawn::ABasePawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComp);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

void ABasePawn::HandleDestruction()
{
	if (ExplosionParticle)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this,
		                                         ExplosionParticle,
		                                         GetActorLocation(),
		                                         GetActorRotation(),
		                                         FVector(1));
	}

	if (DeathSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
	}
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//Rotate turret mesh towards target
void ABasePawn::RotateTurret(FVector TowardsTarget)
{
	const FVector ToTarget = TowardsTarget - TurretMesh->GetComponentLocation();
	//FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	FRotator LookAtRotation = {0.f, ToTarget.Rotation().Yaw, 0.f};

	TurretMesh->SetWorldRotation(LookAtRotation);
}

void ABasePawn::Fire()
{
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass,
	                                                      ProjectileSpawnPoint->GetComponentLocation(),
	                                                      ProjectileSpawnPoint->GetComponentRotation());
	Projectile->SetOwner(this);
}
