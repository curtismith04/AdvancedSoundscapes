// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedSoundscapeSubsystem.h"

void UAdvancedSoundscapeSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
}

void UAdvancedSoundscapeSubsystem::Deinitialize()
{
}


void UAdvancedSoundscapeSubsystem::SpawnGrid(int GridSizeX, int GridSizeY, UInstancedStaticMeshComponent* InstancedStaticMeshComponent, UStaticMesh* MeshToSpawn)
{
    if (!InstancedStaticMeshComponent || !MeshToSpawn)
    {
        UE_LOG(LogTemp, Error, TEXT("Invalid instanced static mesh component or static mesh"));
        return;
    }

    // Clear existing instances in the InstancedStaticMeshComponent
    InstancedStaticMeshComponent->ClearInstances();

    const FVector StartLocation = FVector(0.0f, 0.0f, 0.0f); // Starting location for the grid
    const FVector InstanceOffset = FVector(100.0f, 100.0f, 0.0f); // Offset between instances

    // Loop through each grid position and add an instance of the static mesh
    for (int32 Y = 0; Y < GridSizeY; Y++)
    {
        for (int32 X = 0; X < GridSizeX; X++)
        {
            // Calculate the location for this instance
            FVector InstanceLocation = StartLocation + FVector(X * InstanceOffset.X, Y * InstanceOffset.Y, 0.0f); // Assuming each instance has a size of 100 units

            // Add an instance of the static mesh
            int32 InstanceIndex = InstancedStaticMeshComponent->AddInstanceWorldSpace(FTransform(FRotator::ZeroRotator, InstanceLocation, FVector(1.0f)));

            if (InstanceIndex == INDEX_NONE)
            {
                UE_LOG(LogTemp, Error, TEXT("Failed to add instance of static mesh"));
            }
        }
    }
}

//void UAdvancedSoundscapeSubsystem::SpawnGrid(int GridSizeX, int GridSizeY, TSubclassOf<AActor> TileToSpawn)
//{
//    UWorld* World = GetWorld(); // Get a reference to the world
//
//    if (!World)
//    {
//        UE_LOG(LogTemp, Error, TEXT("Failed to get world"));
//        return;
//    }
//
//    const FVector StartLocation = FVector(0.0f, 0.0f, 0.0f); // Starting location for the grid
//
//    // Loop through each grid position and spawn a cube actor
//    for (int32 Y = 0; Y < GridSizeY; Y++)
//    {
//        for (int32 X = 0; X < GridSizeX; X++)
//        {
//            // Calculate the location for this cube actor
//            FVector SpawnLocation = StartLocation + FVector(X * 100.0f, Y * 100.0f, 0.0f); // Assuming each cube has a size of 100 units
//
//            // Spawn the cube actor
//            AActor* SpawnedActor = World->SpawnActor<AActor>(TileToSpawn, SpawnLocation, FRotator::ZeroRotator);
//
//            if (!SpawnedActor)
//            {
//                UE_LOG(LogTemp, Error, TEXT("Failed to spawn actor"));
//            }
//        }
//    }
//}

void UAdvancedSoundscapeSubsystem::SpawnColorPoints(USceneComponent* BoxComponentToSpawnIn, int MinNumberToSpawn, int MaxNumberToSpawn)
{
    //Local Array for operating on
    TArray<FVector> RandomSpawnVectorArray;
    
    // Determine the size of the array randomly
    int32 ArraySize = FMath::RandRange(MinNumberToSpawn, MaxNumberToSpawn);

    // Resize the array to the determined size
    RandomSpawnVectorArray.Empty();
    RandomSpawnVectorArray.SetNum(ArraySize);


    FBoxSphereBounds SpawnBoxBounds = BoxComponentToSpawnIn->Bounds;
    FVector SpawnAreaWorldLocation = BoxComponentToSpawnIn->GetComponentLocation();

    // Generate random vectors within the specified box using RandomPointInBoundingBox and fill the array
    for (int32 i = 0; i < ArraySize; ++i)
    {
        RandomSpawnVectorArray[i] = UKismetMathLibrary::RandomPointInBoundingBox(SpawnAreaWorldLocation, SpawnBoxBounds.BoxExtent);
    }
}

