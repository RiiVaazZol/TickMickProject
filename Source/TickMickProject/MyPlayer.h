// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
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
	FRotator RotateMash;
	FRotator RotateMashLast;
	//int RotateMode=1;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Move")
	float SpeedRotate =7.f;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Move")
	//float MaxSpeedRotate =500.f;
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Components")
	class UCapsuleComponent* CapsuleComponent;
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Components")
	class UMeshComponent* Mesh;
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Components")
	class USpringArmComponent* CameraArm;
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Components")
	class UCameraComponent* Camera;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Components")
	class UFloatingPawnMovement* MovementComponent;
	void MoveRight(float Value);
	void MoveForward(float Value);
	void SmoothRotateMesh(FRotator Rotate, float DeltaTime);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
