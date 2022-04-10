// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Body");
	CapsuleComponent->InitCapsuleSize(25.f, 95.0f);
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");
	MovementComponent->MaxSpeed = 900.f;
	MovementComponent->Deceleration = 4000.f;
	MovementComponent->TurningBoost = 1.f;
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	Mesh->SetupAttachment(CapsuleComponent);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, -95.0f));
	Mesh->SetRelativeRotation(FRotator(0.f,-90,0));
	RotateMashLast = Mesh->GetRelativeRotation();
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> VisualAsset(TEXT("SkeletalMesh'/Engine/Tutorial/SubEditors/TutorialAssets/Character/TutorialTPP'"));
	if (VisualAsset.Succeeded())
	{
		Mesh->SetSkeletalMesh(VisualAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MeshMat(TEXT("Material'/Engine/EditorMaterials/GridMaterial.GridMaterial'"));
	if (MeshMat.Succeeded())
	{
		Mesh->SetMaterial(0,MeshMat.Object);
	}
	CameraArm = CreateDefaultSubobject<USpringArmComponent>("CameraArm");
	CameraArm->SetupAttachment(CapsuleComponent);
	CameraArm->SetRelativeRotation(FRotator(-55.f,0,0));
	CameraArm->TargetArmLength = 1500.f;
	RotateCamLast = CameraArm->GetRelativeRotation();
	RotateCam = RotateCamLast;
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(CameraArm);
	Camera->SetRelativeRotation(FRotator(-1.f,0,0));
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CapsuleComponent->SetCollisionProfileName(NAME_Pawn);
	CapsuleComponent->BodyInstance.bLockXRotation = true;
	CapsuleComponent->BodyInstance.bLockYRotation = true;
	CapsuleComponent->BodyInstance.SetInstanceSimulatePhysics(true);
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (MovementComponent->Velocity != FVector(0.0f,0.0f,0.0f) && RotateMash!=RotateMashLast)
	{
		RotateMashLast=FMath::RInterpTo(RotateMashLast,RotateMash,DeltaTime,SpeedRotate);
		Mesh->SetRelativeRotation(RotateMashLast);
	}
	if (RotateCam!=RotateCamLast)
	{
		RotateCamLast=FMath::RInterpTo(RotateCamLast,RotateCam,DeltaTime,SpeedRotate);
		CameraArm->SetRelativeRotation(RotateCamLast);
	}
}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("CamRotate", this, &AMyPlayer::CamRotateAxis);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPlayer::MoveRight);

}
void AMyPlayer::CamRotateAxis(float Value)
{
	RotateCam.Yaw+=CamSpeed*Value; 
}
void AMyPlayer::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = CameraArm->GetDesiredRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
		RotateMash = FRotator(0,MovementComponent->Velocity.Rotation().Yaw-90,0);
	}
}
void AMyPlayer::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = CameraArm->GetDesiredRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		// get right vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
		RotateMash = FRotator(0,MovementComponent->Velocity.Rotation().Yaw-90,0);
	}
	
}



