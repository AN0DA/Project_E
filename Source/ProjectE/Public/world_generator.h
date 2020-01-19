// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "biome.h"
#include "fragment.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "world_generator.generated.h"
UCLASS()
class PROJECTE_API Aworld_generator : public AActor
{
	GENERATED_BODY()
public:	
	Aworld_generator();
	UPROPERTY(EditAnywhere, Category = "Water")
	int water_level = 0;
	UPROPERTY(EditAnywhere, Category = "Biomes")
	TArray<Abiome*> biomes;
	UPROPERTY(EditAnywhere, Category = "World Size")
		int horizontal = 10, vertical = 10, number_of_biomes=1;
		
protected:
	virtual void BeginPlay() override;
	
public:	
	virtual void Tick(float DeltaTime) override;
public:
	void Generate_common()
	{
		UWorld* w = GetWorld();
		float temp_hor = 0, temp_ver = 0, temp_high_dif = biomes[0]->heigth_diffrences;
		for (int i = 10;i <= horizontal;i++)
		{
			for (int j = 10;j <= vertical;j++)
			{
				
				float temp_num = FMath::FRandRange(0, temp_high_dif);
				FRotator rot = FRotator(0,0,0);
				FVector vec = FVector(temp_hor, temp_ver, temp_num);
				w->SpawnActor<Afragment>(biomes[0]->fragment, rot, vec);
				
				temp_ver += 125;
			}
			temp_hor += 125;
		}
	}
};
