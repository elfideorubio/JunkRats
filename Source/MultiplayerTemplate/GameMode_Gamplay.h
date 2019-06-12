// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameMode_Gamplay.generated.h"

/**
 *
 */
UCLASS()
class MULTIPLAYERTEMPLATE_API AGameMode_Gamplay : public AGameMode
{
	GENERATED_BODY()

		AGameMode_Gamplay();

public:
	void BeginPlay() override;


	//SpawnZombies
	UFUNCTION(NetMulticast, Reliable)
		void Spawn(class ASpawner_Zombie* SpawnField, int32 CountOfZombies);



private:
	FVector GetPostionOfSpawnedZombie(class UBoxComponent* SpawnField);


};
