// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "biome.h"
#include "fragment.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "world_generator.generated.h"
UCLASS()
class PROJECTE_API Aworld_generator : public AActor
{
	GENERATED_BODY()

public:	
	Aworld_generator();
	UPROPERTY(EditAnywhere, Category = "Activation")
		bool activate = 0;
	UPROPERTY(EditAnywhere, Category = "Water")
	int water_level = 0;
	UPROPERTY(EditAnywhere, Category = "Biomes")
	TArray<Abiome*> biomes;
	UPROPERTY(EditAnywhere, Category = "Core")
		AActor* core;
	//UPROPERTY(EditAnywhere, Category = "Dynamic")
	//TArray<Afragment*> frag_;
	UPROPERTY(EditAnywhere, Category = "Dynamic")
		UClass* Class_;
	
	UPROPERTY(EditAnywhere, Category = "World Size")
		int horizontal = 10;
	UPROPERTY(EditAnywhere, Category = "World Size")
	int vertical = 10;
	UPROPERTY(EditAnywhere, Category = "World Size")
	int number_of_biomes = 1;
protected:
	virtual void BeginPlay() override;
	
public:	
	virtual void Tick(float DeltaTime) override;
public:
	void Generate_common()
	{
		float temp_hor = 0, temp_ver = 0, temp_high_dif = biomes[0]->height_diffrences;
		int a = 0;
		Afragment* f = biomes[0]->fragment;
		UWorld* w = GetWorld();
		for (int i = 0;i <= horizontal;i++)
		{
			for (int j = 0;j <= vertical;j++)
			{

				float temp_num = FMath::FRandRange(0, temp_high_dif);
				FRotator rot = FRotator(0, 0, 0);
				FVector vec = FVector(temp_hor, temp_ver, temp_num);
				 w->SpawnActor<Afragment>(Class_,vec,rot);
				// frag_[a] =
				UE_LOG(LogTemp, Warning, TEXT("Szczecin"));
				temp_ver += 125;
				//a ++ ;
			}
			temp_ver = 0;
			temp_hor += 125;
		}
	}
};
