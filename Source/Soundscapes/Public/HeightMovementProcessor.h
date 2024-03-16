// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "MassEntitySubsystem.h"
#include "HeightMovementProcessor.generated.h"

/**
 * 
 */

UCLASS()
class SOUNDSCAPES_API UHeightMovementProcessor : public UMassProcessor
{
	GENERATED_BODY()

public:
	UHeightMovementProcessor();

protected:
	virtual void ConfigureQueries() override;
	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

private:
	FMassEntityQuery EntityQuery;
};
