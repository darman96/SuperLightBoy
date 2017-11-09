// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BluePieceOfShit.generated.h"

UCLASS()
class SUPERLIGHTBOY_API ABluePieceOfShit : public ACharacter
{
	GENERATED_BODY()

public:

	ABluePieceOfShit();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void OnWallCollisionEnter(AActor* overlappedActor, AActor* other);
	UFUNCTION(BlueprintCallable)
	void OnWallCollisionExit(AActor* overlappedActor, AActor* other);

private:

	void JumpPressed();
	void JumpReleased();

	void MoveRight(float value);

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

private:

	bool allowWallJump;

};
