// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTraitBase.h"
#include "MassEntityTypes.h"
#include "HeightMovementTrait.generated.h"

/**
 * 
 */

USTRUCT()
struct FHeightMovementFragment : public FMassFragment
{
	GENERATED_BODY()
	
	FVector DeltaZ;
	FVector StartLocation;
	bool bStartSet = false;

};


UCLASS()
class SOUNDSCAPES_API UHeightMovementTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()

protected:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const override;
};
