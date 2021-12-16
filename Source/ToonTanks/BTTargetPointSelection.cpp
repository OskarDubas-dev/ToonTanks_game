// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTargetPointSelection.h"

#include "BotTargetPoint.h"
#include "ToonTanksAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

/**
 * @brief Contains logic for the current task
 * @param OwnerComp 
 * @param NodeMemory 
 * @return 
 */
EBTNodeResult::Type UBTTargetPointSelection::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	AToonTanksAIController* AIController = Cast<AToonTanksAIController>(OwnerComp.GetOwner());

	if(AIController)
	{
		UBlackboardComponent* BlackboardComponent = AIController->GetBlackboardComponent();
		ABotTargetPoint* CurrentPoint = Cast<ABotTargetPoint>(BlackboardComponent->GetValueAsObject(("LocationToGo")));

		TArray<AActor*> AvailableTargetPoints = AIController->GetAvailableTargetPoints();

		//Random index to determine the next possible point
		int32 RandomIndex;

		ABotTargetPoint* NextTargetPoint = nullptr;

		//Find a next point which is different from the current one
		do
		{
			RandomIndex = FMath::RandRange(0, AvailableTargetPoints.Num()-1);
			//Array from Controller function contains AActor* objects so cast is needed
			NextTargetPoint = Cast<ABotTargetPoint>(AvailableTargetPoints[RandomIndex]);
			
		}
		while (CurrentPoint == NextTargetPoint);

		//Update the next location in the Blackboard so tank can move to it
		BlackboardComponent->SetValueAsObject("LocationToGo", NextTargetPoint);

		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
	//return Super::ExecuteTask(OwnerComp, NodeMemory);
}
