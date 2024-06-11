// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DezCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_GAMES_DAY_API UDezCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly) float Sprint_MaxWalkSpeed;
	UPROPERTY(EditDefaultsOnly) float Walk_MaxWalkSpeed;
	
	bool SAFE_bWantsToSprint;

public:
	UDezCharacterMovementComponent();
	virtual FNetworkPredictionData_Client* GetPredictionData_Client() const override;
	virtual void UpdateFromCompressedFlags(uint8 Flags) override;

	uint8 bWantsToSprint : 1;

protected:
	virtual void OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity) override;


public:
	UFUNCTION(BlueprintCallable) void SetSprinting(bool Sprint);
};


class FSavedMove_Dez : public FSavedMove_Character
{
public:
	typedef FSavedMove_Character Super;

	virtual bool CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InCharacter, float MaxDelta) const override;
	virtual void Clear() override;
	virtual uint8 GetCompressedFlags() const override;
	virtual void SetMoveFor(ACharacter* C, float InDeltaTime, FVector const& NewAccel, FNetworkPredictionData_Client_Character& ClientData) override;
	virtual void PrepMoveFor(ACharacter* C) override;

	uint8 Saved_bWantsToSprint : 1;
};



class FNetworkPredictionData_Client_Dez : public FNetworkPredictionData_Client_Character
{
public:
	FNetworkPredictionData_Client_Dez(const UCharacterMovementComponent& ClientMovement) : Super(ClientMovement) {};

	typedef FNetworkPredictionData_Client_Character Super;
	virtual FSavedMovePtr AllocateNewMove() override;
};