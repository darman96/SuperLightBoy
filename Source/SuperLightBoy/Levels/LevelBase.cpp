// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelBase.h"

#include "Camera/CameraComponent.h"
#include "Character/BluePieceOfShit.h"
#include "GameFramework/SpringArmComponent.h"
#include "EngineUtils.h"


// Sets default values
ALevelBase::ALevelBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = .2f;
}

// Called when the game starts or when spawned
void ALevelBase::BeginPlay()
{
	Super::BeginPlay();
	
	// Ensure that the Actor is in the Scene center
	SetActorLocation(FVector(0.f, 0.f, 0.f));

	// Get reference to player character
	for (TActorIterator<ACharacter> actorItr(GetWorld()); actorItr; ++actorItr)
	{
		playerCharacter = Cast<ABluePieceOfShit>(*actorItr);
	}
}

// Called every frame
void ALevelBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
