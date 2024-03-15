// Fill out your copyright notice in the Description page of Project Settings.


#include "MassStateTreeData.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "MassStateTreeExecutionContext.h"

void FMassSTEGetPlayerLocation::TreeStart(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.PlayerCharacter = UGameplayStatics::GetPlayerCharacter(Context.GetWorld(), 0);
}

void FMassSTEGetPlayerLocation::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.PlayerLocation = InstanceData.PlayerCharacter->GetActorLocation();
}
