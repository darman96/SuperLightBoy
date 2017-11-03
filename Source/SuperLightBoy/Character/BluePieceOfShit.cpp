// Fill out your copyright notice in the Description page of Project Settings.

#include "BluePieceOfShit.h"

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

	GetCapsuleComponent()->InitCapsuleSize(25.f, 25.f);

	/*CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true;
	CameraBoom->bUsePawnControlRotation = false;
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.0f;
	CameraBoom->RelativeRotation = FRotator(0.f, -90.f, 0.f);

	SideViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Side View Camera"));
	SideViewCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCamera->bUsePawnControlRotation = false;*/

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 800.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// Setup Wall Collision
	WallCollisionBox = CreateDefaultSubobject<UBoxComponent>("WallCollisionBox");
	WallCollisionBox->InitBoxExtent(FVector(10.f, 30.f, 30.f));
	WallCollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	WallCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABluePieceOfShit::OnHitWall);

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
	Jump();
}

void ABluePieceOfShit::JumpReleased()
{
	StopJumping();
}

void ABluePieceOfShit::MoveRight(float value)
{
	AddMovementInput(FVector(1.f, 0.f, 0.f), value);
}

void ABluePieceOfShit::OnHitWall(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Display, TEXT("Collision With Wall!!!!!!!"));
}