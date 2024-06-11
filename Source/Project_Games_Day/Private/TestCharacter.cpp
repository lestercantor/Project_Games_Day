// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter.h"
#include "DezCharacterMovementComponent.h"

// Sets default values
ATestCharacter::ATestCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UDezCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// DezCharacterMovementComponent = Cast<UDezCharacterMovementComponent>(GetCharacterMovement());
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

