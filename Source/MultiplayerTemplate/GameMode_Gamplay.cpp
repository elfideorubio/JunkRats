// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode_Gamplay.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "Spawner_Zombie.h"
#include "Zombie_Base.h"
#include "TimerManager.h"

AGameMode_Gamplay::AGameMode_Gamplay()
{

}

void AGameMode_Gamplay::BeginPlay()
{
	Super::BeginPlay();
}



FVector AGameMode_Gamplay::GetPostionOfSpawnedZombie(UBoxComponent* SpawnField)
{
	for(;;)
	{
		FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(SpawnField->Bounds.Origin, SpawnField->Bounds.BoxExtent);

		FHitResult HitTest;
		FCollisionShape Sphere;
		Sphere.SetSphere(25.f);

		GetWorld()->SweepSingleByChannel(HitTest, SpawnLocation, SpawnLocation, FQuat::Identity, ECollisionChannel::ECC_Visibility, Sphere);
		if (!HitTest.bBlockingHit)
		{
			return SpawnLocation;
		}
	}

	return FVector(0.0f);
}

void AGameMode_Gamplay::Spawn_Implementation(class ASpawner_Zombie* SpawnField, int32 CountOfZombies)
{
	if (SpawnField->ZombiesToSpawn.Num() <= 0) return;
	

	int32 ZombieIndex = 0;
	
	for(int i = 0; i < CountOfZombies; i++)
	{
		if (SpawnField->ZombiesToSpawn.Num() > 1)
		{
			ZombieIndex = FMath::RandHelper(SpawnField->ZombiesToSpawn.Num() - 1);
		}
		FVector SpawnLocation = GetPostionOfSpawnedZombie(SpawnField->SpawnField);
		GetWorld()->SpawnActor<AZombie_Base>(SpawnField->ZombiesToSpawn[ZombieIndex], SpawnLocation, FRotator::ZeroRotator);

	}


}
