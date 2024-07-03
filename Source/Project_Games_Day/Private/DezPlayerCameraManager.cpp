// Fill out your copyright notice in the Description page of Project Settings.


#include "DezPlayerCameraManager.h"

#include "DezCharacterMovementComponent.h"
#include "TestCharacter.h"
#include "Components/CapsuleComponent.h"

ADezPlayerCameraManager::ADezPlayerCameraManager()
{
}

//void ADezPlayerCameraManager::UpdateViewTarget(FTViewTarget& OutVT, float DeltaTime)
//{
//	Super::UpdateViewTarget(OutVT, DeltaTime);
//
//	if (ATestCharacter* TestCharacter = Cast<ATestCharacter>(GetOwningPlayerController()->GetPawn()))
//	{
//		UDezCharacterMovementComponent* DezCMC = TestCharacter->GetDezCharacterMovement();
//		FVector TargetCrouchOffset = FVector(
//			0,
//			0,
//			DezCMC->GetCrouchedHalfHeight() - TestCharacter->GetClass()->GetDefaultObject<ACharacter>()->GetCapsuleComponent()->GetScaledCapsuleHalfHeight());
//
//		FVector Offset = FMath::Lerp(FVector::ZeroVector, TargetCrouchOffset, FMath::Clamp(CrouchBlendTime / CrouchBlendDuration, 0.0f, 1.0f));
//
//
//		if (DezCMC->IsCrouching())
//		{
//			CrouchBlendTime = FMath::Clamp(CrouchBlendTime + DeltaTime, 0.0f, CrouchBlendDuration);
//			Offset -= TargetCrouchOffset;
//		}
//		else
//		{
//			CrouchBlendTime = FMath::Clamp(CrouchBlendTime - DeltaTime, 0.0f, CrouchBlendDuration);
//
//		}
//
//		if (DezCMC->IsMovingOnGround())
//		{
//			OutVT.POV.Location += Offset;
//		}
//	}
//}
