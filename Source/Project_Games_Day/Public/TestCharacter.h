// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestCharacter.generated.h"

UCLASS(config=Game)
class PROJECT_GAMES_DAY_API ATestCharacter : public ACharacter
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Movement) class UDezCharacterMovementComponent* DezCharacterMovementComponent;

public:
	// Sets default values for this character's properties
	ATestCharacter(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE UDezCharacterMovementComponent* GetDezCharacterMovement() const { return DezCharacterMovementComponent; }
};
