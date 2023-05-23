// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "MyPlayer.generated.h"


UCLASS()
class TICKMICKPROJECT_API AMyPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float CamSpeed=0.8f;
	FVector CursorTraceStart;
	FVector CursorTraceVector;
	FHitResult CursorTraceEnd;
	FRotator RotateCam;
	FRotator RotateCamLast;
	FRotator RotateMash;
	FRotator RotateMashLast;
	bool isHit;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Move")
	float SpeedRotate =7;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Components")
	 class UCapsuleComponent* CapsuleComponent;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Components")
	class USkeletalMeshComponent* Mesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Components")
	class USpringArmComponent* CameraArm;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Components")
	class UCameraComponent* Camera;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Components")
	class UFloatingPawnMovement* MovementComponent;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Components")
	class APlayerController* PlayerController;
	void MoveRight(float Value);
	void MoveForward(float Value);
	void CamRotateAxis(float Value);
	//void CamRotate90();
	public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};