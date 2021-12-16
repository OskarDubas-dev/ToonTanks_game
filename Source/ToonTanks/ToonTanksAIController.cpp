// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksAIController.h"
#include "EnemyTank.h"
#include "BotTargetPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Kismet/GameplayStatics.h"

AToonTanksAIController::AToonTanksAIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	LocationToGoKey = "LocationToGo";
	
}

/**
 * @brief Called on Possess. Populate the array of available bot target points.
 * When exact point is needed to compare it can be casted to corresponding class (ABotTargetPoint)*
 * @param TankPawn 
 */
void AToonTanksAIController::OnPossess(APawn* TankPawn)
{
	Super::OnPossess(TankPawn);

	AEnemyTank* EnemyTank = Cast<AEnemyTank>(TankPawn);


	if (EnemyTank)
	{
		if (EnemyTank->BehaviorTree->BlackboardAsset)
		{
			BlackboardComponent->InitializeBlackboard(*(EnemyTank->BehaviorTree->BlackboardAsset));
			UE_LOG(LogTemp, Warning, TEXT("blackboard initialized for enemy tank"));
		}
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABotTargetPoint::StaticClass(), BotTargetPoints);

		BehaviorTreeComponent->StartTree(*EnemyTank->BehaviorTree);
	}
}
