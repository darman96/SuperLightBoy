// Fill out your copyright notice in the Description page of Project Settings.

#include "SuperLightBoyCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASuperLightBoyCharacter::ASuperLightBoyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCapsuleComponent()->InitCapsuleSize(25.f, 25.f);

	cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	cameraBoom->SetupAttachment(RootComponent);
	cameraBoom->bAbsoluteRotation = true;
	cameraBoom->bUsePawnControlRotation = false;
	cameraBoom->bDoCollisionTest = false;
	cameraBoom->TargetArmLength = 500.0f;
	cameraBoom->RelativeRotation = FRotator(0.f, 0.f, -90.f);

	sideViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Side View Camera"));
	sideViewCamera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName);
	sideViewCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

}

// Called to bind functionality to input
void ASuperLightBoyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveRight", this, &ASuperLightBoyCharacter::MoveRight);

}

void ASuperLightBoyCharacter::MoveRight(float value)
{
	AddMovementInput(FVector(1.f, 0.f, 0.f), value);
}

