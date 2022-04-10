// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelGeneration.h"

// Sets default values
ALevelGeneration::ALevelGeneration()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelGeneration::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelGeneration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

