// Fill out your copyright notice in the Description page of Project Settings.


#include "DezCharacterMovementComponent.h"
#include "GameFramework/Character.h"

UDezCharacterMovementComponent::UDezCharacterMovementComponent()
{
    NavAgentProps.bCanCrouch = true;
}

bool FSavedMove_Dez::CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InCharacter, float MaxDelta) const
{
    // FSavedMove_Dez* NewDezMove = static_cast<FSavedMove_Dez*>(NewMove.Get());

    if (Saved_bWantsToSprint != ((FSavedMove_Dez*)&NewMove)->Saved_bWantsToSprint)
    {
        return false;
    }

    return Super::CanCombineWith(NewMove, InCharacter, MaxDelta);
}

void FSavedMove_Dez::Clear()
{
    Super::Clear();

    Saved_bWantsToSprint = 0;
}

uint8 FSavedMove_Dez::GetCompressedFlags() const
{
    uint8 Result = Super::GetCompressedFlags();

    if (Saved_bWantsToSprint)
    {
        Result |= FLAG_Custom_0;
    }

    return Result;
}

void FSavedMove_Dez::SetMoveFor(ACharacter* C, float InDeltaTime, FVector const& NewAccel, FNetworkPredictionData_Client_Character& ClientData)
{
    Super::SetMoveFor(C, InDeltaTime, NewAccel, ClientData);
    
    UDezCharacterMovementComponent* CharacterMovement = Cast<UDezCharacterMovementComponent>(C->GetCharacterMovement());

    Saved_bWantsToSprint = CharacterMovement->bWantsToSprint;
}

void FSavedMove_Dez::PrepMoveFor(ACharacter* C)
{
    Super::PrepMoveFor(C);

    UDezCharacterMovementComponent* CharacterMovement = Cast<UDezCharacterMovementComponent>(C->GetCharacterMovement());

    CharacterMovement->bWantsToSprint = Saved_bWantsToSprint;
}

FSavedMovePtr FNetworkPredictionData_Client_Dez::AllocateNewMove()
{
    return FSavedMovePtr(new FSavedMove_Dez());
}

FNetworkPredictionData_Client* UDezCharacterMovementComponent::GetPredictionData_Client() const
{
    if (!ClientPredictionData)
    {
        if (UDezCharacterMovementComponent* MutableThis = const_cast<UDezCharacterMovementComponent*>(this))
        {
            MutableThis->ClientPredictionData = new FNetworkPredictionData_Client_Dez(*this);
            MutableThis->ClientPredictionData->MaxSmoothNetUpdateDist = 92.0f;
            MutableThis->ClientPredictionData->NoSmoothNetUpdateDist = 140.0f;
        }
    }

    return ClientPredictionData;
}

void UDezCharacterMovementComponent::UpdateFromCompressedFlags(uint8 Flags)
{
    Super::UpdateFromCompressedFlags(Flags);

    bWantsToSprint = (Flags & FSavedMove_Character::FLAG_Custom_0) != 0;
}

void UDezCharacterMovementComponent::OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity)
{
    Super::OnMovementUpdated(DeltaSeconds, OldLocation, OldVelocity);

    if (MovementMode == MOVE_Walking)
    {
        if (bWantsToSprint)
        {
            MaxWalkSpeed = Sprint_MaxWalkSpeed;
        }
        else
        {
            MaxWalkSpeed = Walk_MaxWalkSpeed;
        }
    }
}

void UDezCharacterMovementComponent::SetSprinting(bool Sprint)
{
    bWantsToSprint = Sprint;
}

void UDezCharacterMovementComponent::CrouchPressed()
{
    bWantsToCrouch = !bWantsToCrouch;
}

