// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombie_Base.h"
#include "Zombie_TEST.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERTEMPLATE_API AZombie_TEST : public AZombie_Base
{
	GENERATED_BODY()

public:

	void BeginPlay() override;
	
};
