// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelBackground.generated.h"

UCLASS()
class SUPERLIGHTBOY_API ALevelBackground : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelBackground();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// Get all references to other actors needed here
	void GetActorReferences();

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* backgroundPlane;
	
	class ABluePieceOfShit* characterReference;
	class ALevelBase* levelReference;

};
