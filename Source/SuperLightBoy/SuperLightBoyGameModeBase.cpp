// Fill out your copyright notice in the Description page of Project Settings.

#include "SuperLightBoyGameModeBase.h"

#include "Character/SuperLightBoyCharacter.h"
#include "UObject/ConstructorHelpers.h"

//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));

ASuperLightBoyGameModeBase::ASuperLightBoyGameModeBase()
{
	DefaultPawnClass = ASuperLightBoyCharacter::StaticClass();
}