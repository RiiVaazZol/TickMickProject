// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoomGeneration.generated.h"

UCLASS()
class TICKMICKPROJECT_API ARoomGeneration : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoomGeneration();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Room")
	float RoomLenght;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Room")
	float RoomWidth;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Components")
	class UStaticMeshComponent* Room;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
