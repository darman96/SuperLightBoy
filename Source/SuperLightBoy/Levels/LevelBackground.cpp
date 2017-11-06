// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelBackground.h"

#include "Components/StaticMeshComponent.h"
#include "Character/BluePieceOfShit.h"
#include "EngineUtils.h"
#include "LevelBase.h"

// Sets default values
ALevelBackground::ALevelBackground()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	backgroundPlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Background Plane"));

}

// Called when the game starts or when spawned
void ALevelBackground::BeginPlay()
{
	Super::BeginPlay();
	
	GetActorReferences();

	// Set background position relative to characterPosition
	FVector characterPos = characterReference->GetActorLocation();
	FVector levelExtends = levelReference->LevelExtends;

	FVector newBackgroundPos;

	newBackgroundPos.X = FMath::Clamp(characterPos.X * 0.25f, -levelExtends.X, levelExtends.X);
	newBackgroundPos.Y = FMath::Clamp(characterPos.Y * 0.25f, -levelExtends.Y, levelExtends.Y);

	SetActorLocation(newBackgroundPos);
}

// Called every frame
void ALevelBackground::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Set background position relative to characterPosition
	FVector characterPos = characterReference->GetActorLocation();
	FVector levelExtends = levelReference->LevelExtends;

	FVector newBackgroundPos = GetActorLocation();

	newBackgroundPos.X = FMath::Clamp(characterPos.X * .5f, -levelExtends.X, levelExtends.X);
	newBackgroundPos.Z = FMath::Clamp(characterPos.Z * .4f, -levelExtends.Z, levelExtends.Z);

	SetActorLocation(newBackgroundPos);
}

void ALevelBackground::GetActorReferences()
{
	// Get reference to character
	for (TActorIterator<ACharacter> actorItr(GetWorld()); actorItr; ++actorItr)
	{
		characterReference = Cast<ABluePieceOfShit>(*actorItr);
	}

	// Get reference to level
	for (TActorIterator<ALevelBase> actorItr(GetWorld()); actorItr; ++actorItr)
	{
		levelReference = *actorItr;
	}

}