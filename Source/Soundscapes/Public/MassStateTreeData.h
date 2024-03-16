// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MassStateTreeTypes.h"
#include "MassStateTreeData.generated.h"

/**
 * 
 */

struct FMassStateTreeExecutionContext;

USTRUCT()
struct FMassPlayerLocationInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Output)
	FVector PlayerLocation;

	UPROPERTY()
	ACharacter* PlayerCharacter;
};

USTRUCT(BlueprintType)
struct FMassSTEGetPlayerLocation : public FMassStateTreeEvaluatorBase
{

	GENERATED_BODY()

	using FInstanceDataType = FMassPlayerLocationInstanceData;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

	virtual void TreeStart(FStateTreeExecutionContext& Context) const override;

	virtual void Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;

};


USTRUCT()
struct FMassChangeLocationTaskInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Input)
	FVector TargetLocation;

};

USTRUCT()
struct FMassChangeLocationTask : public FMassStateTreeTaskBase
{
	GENERATED_BODY()

	using FInstanceDataType = FMassChangeLocationTaskInstanceData;

protected:
	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;

};

UCLASS()
class SOUNDSCAPES_API UMassStateTreeData : public UObject
{
	GENERATED_BODY()
	
};
