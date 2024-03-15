// Copyright Epic Games, Inc. All Rights Reserved.

#include "SoundscapesGameMode.h"
#include "SoundscapesCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASoundscapesGameMode::ASoundscapesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
