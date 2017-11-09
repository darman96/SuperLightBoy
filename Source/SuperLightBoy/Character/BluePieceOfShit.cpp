// Fill out your copyright notice in the Description page of Project Settings.

#include "BluePieceOfShit.h"

#include "Engine.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ABluePieceOfShit::ABluePieceOfShit()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	bGenerateOverlapEventsDuringLevelStreaming = true;

	GetCapsuleComponent()->InitCapsuleSize(25.f, 25.f);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true;
	CameraBoom->bUsePawnControlRotation = false;
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.0f;
	CameraBoom->RelativeRotation = FRotator(-15.f, -90.f, 0.f);

	SideViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Side View Camera"));
	SideViewCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 800.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	allowWallJump = false;
}

void ABluePieceOfShit::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ABluePieceOfShit::OnWallCollisionEnter);
	OnActorEndOverlap.AddDynamic(this, &ABluePieceOfShit::OnWallCollisionExit);
}

void ABluePieceOfShit::Tick(float DeltaTime)
{
	FVector location = GetActorLocation();
	location.Y = 0.f;
	SetActorLocation(location);
}

// Called to bind functionality to input
void ABluePieceOfShit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABluePieceOfShit::JumpPressed);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ABluePieceOfShit::JumpReleased);

	PlayerInputComponent->BindAxis("MoveRight", this, &ABluePieceOfShit::MoveRight);
}

void ABluePieceOfShit::JumpPressed()
{
	if (!GetCharacterMovement()->IsFalling())
	{
		Jump();
		return;
	}
	else
	{
		if (allowWallJump)
		{
			GetCharacterMovement()->Launch(FVector(-300.f, 0.f, 1000.f));
		}
	}
}

void ABluePieceOfShit::JumpReleased()
{
	if (!GetCharacterMovement()->IsFalling())
	{
		StopJumping();
		return;
	}
	else
	{
	}
}

void ABluePieceOfShit::MoveRight(float value)
{
	AddMovementInput(FVector(1.f, 0.f, 0.f), value);
}

void ABluePieceOfShit::OnWallCollisionEnter(AActor* overlappedActor, AActor* other)
{
	allowWallJump = true;
}

void ABluePieceOfShit::OnWallCollisionExit(AActor* overlappedActor, AActor* other)
{
	allowWallJump = false;
}