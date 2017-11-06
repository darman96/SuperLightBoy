// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelBase.generated.h"

UCLASS()
class SUPERLIGHTBOY_API ALevelBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Level)
	FVector LevelExtends;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Level)
	class UStaticMeshComponent* LevelBackground;

private:

	class ABluePieceOfShit* playerCharacter;

};
