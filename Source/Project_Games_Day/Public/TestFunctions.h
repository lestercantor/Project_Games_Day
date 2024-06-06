// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TestFunctions.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_GAMES_DAY_API UTestFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		UFUNCTION(BlueprintCallable, Category = "Sound on Minimised")
		static void Unfocused(bool EnableSoundInBackground);

		UFUNCTION(BlueprintCallable, Category = "Sound on Minimised")
		static void MicInputTest(float InputVolume);
};
