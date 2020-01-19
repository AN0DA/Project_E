// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "fragment.h"
#include "biome.generated.h"

UCLASS()
class PROJECTE_API Abiome : public AActor
{
	GENERATED_BODY()
	
public:	
	Abiome();
	UPROPERTY(EditAnywhere, Category = "Heigth")
		float top_lvl = 0, floor_lvl = 0,heigth_diffrences=5;
	UPROPERTY(EditAnywhere, Category = "Block")
		Afragment* fragment;
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
