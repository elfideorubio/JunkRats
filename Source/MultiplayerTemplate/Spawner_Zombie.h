// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner_Zombie.generated.h"

UCLASS()
class MULTIPLAYERTEMPLATE_API ASpawner_Zombie : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner_Zombie();

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* SpawnField;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<class AZombie_Base>> ZombiesToSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
