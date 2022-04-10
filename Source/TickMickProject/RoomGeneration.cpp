// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomGeneration.h"

// Sets default values
ARoomGeneration::ARoomGeneration()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Room = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (VisualAsset.Succeeded())
	{
		Room->SetStaticMesh(VisualAsset.Object);
	}
}

// Called when the game starts or when spawned
void ARoomGeneration::BeginPlay()
{
	Super::BeginPlay();
	RoomLenght = ((float)FMath::RandRange(5,30));
	RoomWidth = ((float)FMath::RandRange(5,30));
	Room->SetWorldLocation(FVector(0.0f, 0.0f, 25.0f));
	Room->SetRelativeScale3D(FVector(RoomWidth, RoomLenght, 0.1f));
}

// Called every frame
void ARoomGeneration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

