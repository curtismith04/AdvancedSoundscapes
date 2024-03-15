// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "SoundscapeFloorTile.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/InstancedStaticMeshComponent.h"

#include "AdvancedSoundscapeSubsystem.generated.h"


/**
 * 
 */
UCLASS()
class SOUNDSCAPES_API UAdvancedSoundscapeSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;



	UFUNCTION(BlueprintCallable, Category = "AdvancedSoundscapes | GridFloor")
	void SpawnGrid(int GridSizeX, int GridSizeY, UInstancedStaticMeshComponent* InstancedStaticMeshComponent, UStaticMesh* MeshToSpawn);
	//void SpawnGrid(int GridSizeX, int GridSizeY, TSubclassOf<AActor> TileToSpawn);

	UFUNCTION(BlueprintCallable, Category = "AdvancedSoundscapes | Soundscape")
	void SpawnColorPoints(USceneComponent* BoxComponentToSpawnIn, int MinNumberToSpawn, int MaxNumberToSpawn);

};
