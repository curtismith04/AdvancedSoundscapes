// Fill out your copyright notice in the Description page of Project Settings.
#include "HeightMovementProcessor.h"
#include "MassCommonTypes.h"
#include "MassCommonFragments.h"
#include "HeightMovementTrait.h"
#include "Kismet/GameplayStatics.h"
#include "MassExecutionContext.h"
#include "GameFramework/Character.h"

UHeightMovementProcessor::UHeightMovementProcessor()
{
	bAutoRegisterWithProcessingPhases = true;
	ExecutionFlags = (int32)EProcessorExecutionFlags::All;
	ExecutionOrder.ExecuteBefore.Add(UE::Mass::ProcessorGroupNames::Avoidance);
}

void UHeightMovementProcessor::ConfigureQueries()
{
	UE_VLOG(this, LogMass, Warning, TEXT("Query Configure"));
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadWrite);
	EntityQuery.AddRequirement<FHeightMovementFragment>(EMassFragmentAccess::ReadWrite);
}

void UHeightMovementProcessor::Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context)
{
	EntityQuery.ForEachEntityChunk(EntityManager, Context, ([this](FMassExecutionContext& Context)
		{
			UE_VLOG(this, LogMass, Warning, TEXT("Processor Executing"));
			const TArrayView <FTransformFragment>TransformList = Context.GetMutableFragmentView<FTransformFragment>();
			const TArrayView<FHeightMovementFragment> HeightMovementList = Context.GetMutableFragmentView<FHeightMovementFragment>();

			for (int32 EI = 0; EI < Context.GetNumEntities(); EI++)
			{
				//If this is the first iteration set the initial location of the entity
				if (!HeightMovementList[EI].bStartSet)
				{
					FVector& Start = HeightMovementList[EI].StartLocation;
					Start = TransformList[EI].GetMutableTransform().GetLocation();
					bool& Set = HeightMovementList[EI].bStartSet;
					Set = true;
				}

				FVector& Delta = HeightMovementList[EI].DeltaZ;
				FVector CurrentLocation = TransformList[EI].GetMutableTransform().GetLocation();

				ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(Context.GetWorld(), 0);
				if (PlayerCharacter)
				{
					double Distance = FVector::Dist(CurrentLocation, PlayerCharacter->GetActorLocation());
					Delta = { 0,0,0 };
					if (Distance > 1000.0f) { Delta = { 0,0,50 }; }
					else if (Distance > 1500.0f) { Delta = { 0,0,100 }; }
				}
				FTransform& Transform = TransformList[EI].GetMutableTransform();

				Transform.SetLocation(HeightMovementList[EI].StartLocation + Delta);
			}
		}));

	UE_VLOG(this, LogMass, Warning, TEXT("Execute"));
}
