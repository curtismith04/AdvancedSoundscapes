// Fill out your copyright notice in the Description page of Project Settings.


#include "MassStateTreeData.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "MassAIBehaviorTypes.h"
#include "MassStateTreeExecutionContext.h"

void FMassSTEGetPlayerLocation::TreeStart(FStateTreeExecutionContext& Context) const
{
	
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.PlayerCharacter = UGameplayStatics::GetPlayerCharacter(Context.GetWorld(), 0);
}

void FMassSTEGetPlayerLocation::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (InstanceData.PlayerCharacter)
	{
		InstanceData.PlayerLocation = InstanceData.PlayerCharacter->GetActorLocation();
	}
}

EStateTreeRunStatus FMassChangeLocationTask::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	return EStateTreeRunStatus::Running;
}

void FMassChangeLocationTask::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
}

EStateTreeRunStatus FMassChangeLocationTask::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	MASSBEHAVIOR_LOG(Warning, TEXT("Player Location: %s"), *InstanceData.TargetLocation.ToString());
	return EStateTreeRunStatus::Running;
}
