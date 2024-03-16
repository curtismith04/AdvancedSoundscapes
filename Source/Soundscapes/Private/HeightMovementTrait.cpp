// Fill out your copyright notice in the Description page of Project Settings.


#include "HeightMovementTrait.h"
#include "MassEntityTemplateRegistry.h"

void UHeightMovementTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const
{
	BuildContext.AddFragment<FHeightMovementFragment>();
}
