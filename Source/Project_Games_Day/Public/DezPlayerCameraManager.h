// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "DezPlayerCameraManager.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_GAMES_DAY_API ADezPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()


	UPROPERTY(EditDefaultsOnly) float CrouchBlendDuration = 0.15f;
	float CrouchBlendTime;
public:
	ADezPlayerCameraManager();

	//virtual void UpdateViewTarget(FTViewTarget& OutVT, float DeltaTime) override;
};
