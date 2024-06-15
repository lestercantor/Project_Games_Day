// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter.h"
#include "DezCharacterMovementComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ATestCharacter::ATestCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UDezCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	DezCharacterMovementComponent = Cast<UDezCharacterMovementComponent>(GetCharacterMovement());

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(GetRootComponent());
	PlayerCamera->SetRelativeLocation(FVector(-10.0f, 0.0f, 60.0f));
	PlayerCamera->bUsePawnControlRotation = true;

	CrouchEyeOffset = FVector::ZeroVector;
	CrouchSpeed = 12.0f;
}

//void ATestCharacter::OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust)
//{
//	if (HalfHeightAdjust == 0)
//	{
//		return;
//	}
//
//	float StartBaseEyeHeight = BaseEyeHeight;
//	Super::OnStartCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);
//	CrouchEyeOffset.Z += StartBaseEyeHeight - BaseEyeHeight + HalfHeightAdjust;
//	PlayerCamera->SetRelativeLocation(FVector(-10.0f, 0.0f, BaseEyeHeight), false);
//}
//
//void ATestCharacter::OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust)
//{
//	if (HalfHeightAdjust == 0)
//	{
//		return;
//	}
//
//	float StartBaseEyeHeight = BaseEyeHeight;
//	Super::OnStartCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);
//	CrouchEyeOffset.Z += StartBaseEyeHeight - BaseEyeHeight - HalfHeightAdjust;
//	PlayerCamera->SetRelativeLocation(FVector(-10.0f, 0.0f, BaseEyeHeight), false);
//}
//
//void ATestCharacter::CalcCamera(float DeltaTime, FMinimalViewInfo& OutResult)
//{
//	if (PlayerCamera)
//	{
//		PlayerCamera->GetCameraView(DeltaTime, OutResult);
//		OutResult.Location += CrouchEyeOffset;
//	}
//}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//float CrouchInterpTime = FMath::Min(1.0f, CrouchSpeed * DeltaTime);
	//CrouchEyeOffset = (1.0f - CrouchInterpTime) * CrouchEyeOffset;
}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

