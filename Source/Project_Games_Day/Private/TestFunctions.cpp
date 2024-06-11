// Fill out your copyright notice in the Description page of Project Settings.


#include "TestFunctions.h"
#include "Misc/App.h"
#include "Net/VoiceConfig.h"

void UTestFunctions::Unfocused(bool EnableSoundInBackground)
{
	if (EnableSoundInBackground == true)
	{
		FApp::SetUnfocusedVolumeMultiplier(1.0f);
	}
	else
	{
		FApp::SetUnfocusedVolumeMultiplier(0.0f);
	}
}

void UTestFunctions::MicInputTest(float InputVolume)
{
	IConsoleVariable* Gain = IConsoleManager::Get().FindConsoleVariable(TEXT("voice.MicInputGain"));

	Gain->Set(InputVolume);

	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Some variable values: x: %f"), InputVolume));
}
