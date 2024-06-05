// Fill out your copyright notice in the Description page of Project Settings.


#include "TestFunctions.h"
#include "Misc/App.h"

void UTestFunctions::Unfocused(bool isChecked)
{
	if (isChecked == true)
	{
		FApp::SetUnfocusedVolumeMultiplier(1.0f);
	}
	else
	{
		FApp::SetUnfocusedVolumeMultiplier(0.0f);
	}

}
