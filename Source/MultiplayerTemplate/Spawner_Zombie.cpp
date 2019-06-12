// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner_Zombie.h"
#include "Components/BoxComponent.h"
#include "GameMode_Gamplay.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Sets default values
ASpawner_Zombie::ASpawner_Zombie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpawnField = CreateDefaultSubobject<UBoxComponent>("Spawn Field");
	RootComponent = SpawnField;
}

// Called when the game starts or when spawned
void ASpawner_Zombie::BeginPlay()
{
	Super::BeginPlay();

	AGameMode_Gamplay* GameMode_Gameplay = Cast<AGameMode_Gamplay>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode_Gameplay)
	{
		GameMode_Gameplay->Spawn(this, 5);
	}
	
}

// Called every frame
void ASpawner_Zombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

