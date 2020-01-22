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
	UPROPERTY(EditAnywhere, Category = "Dynamic")
	TArray<Afragment*> frag_;
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
		int y = biomes[0]->amplitude,u = -1;
		Afragment* f = biomes[0]->fragment;
		UWorld* w = GetWorld();
		for (int i = 0;i < horizontal;i++)
		{
			for (int j = 0;j < vertical;j++)
			{
				bool y_count = false;
				float temp_num = FMath::FRandRange(0, temp_high_dif); //random number temp_num
				float temp_num2 = temp_num; // tn2=tn
				float v = FMath::Abs(y);
				if (y == 0)
				{
					temp_num2 = FMath::FRandRange(0, temp_high_dif); //new seed
					y += u;
				}

				
				v = FMath::Abs(y);
				temp_num = (temp_num2 / biomes[0]->amplitude) * (biomes[0]->amplitude / v);
				y+=u;

				FRotator rot = FRotator(0, 0, 0);
				FVector vec = FVector(temp_hor, temp_ver, temp_num);
				Afragment* a = w->SpawnActor<Afragment>(Class_,vec,rot);
				frag_.Add(a);
				a->line = i;
				//UE_LOG(LogTemp, Warning, TEXT("Szczecin"));
				temp_ver += 128;
				if (y < -biomes[0]->amplitude)
				{
					u = 1;
				}
				if (y > biomes[0]->amplitude)
				{
					u = -1;
				}
				
			}
			temp_ver = 0;
			temp_hor += 128;
		}
		int problems = 1;
		float temp_num = (horizontal * vertical)-1;
		
		for (int i = 0;i < temp_num;i++)
		{
			//"making" neightbours of block inside his tab
			// 1,1  2,1  3,1
 			// 2,1  XXX  3,2
			// 3,1  3,2  3,3
			if (i<temp_num&& frag_[i]->line == frag_[i + 1]->line) // 2,1 S
			frag_[i]->frag_tab.Add(frag_[i+1]);
			if (i >= 1 && frag_[i]->line == frag_[i - 1]->line)  // 2,3 S
			frag_[i]->frag_tab.Add(frag_[i - 1]);
			if (i< temp_num-vertical&& frag_[i]->line == frag_[i + vertical]->line+1) //3,2 S
			frag_[i]->frag_tab.Add(frag_[i + vertical]);
			if (i < (temp_num - vertical)-1 && frag_[i]->line == frag_[i + vertical+1]->line + 1) //3,1 S
			frag_[i]->frag_tab.Add(frag_[i + 1+vertical]);
			if (i < (temp_num - vertical) + 1 && frag_[i]->line == frag_[i + vertical-1]->line + 1) //3,2 S
			frag_[i]->frag_tab.Add(frag_[i - 1+vertical]);
			if (i >= vertical&& frag_[i]->line == frag_[i - vertical]->line - 1) //1,1
			frag_[i]->frag_tab.Add(frag_[i - vertical]);
			if (i >= vertical-1 && frag_[i]->line == frag_[i -vertical+1]->line - 1) // 2,1
			frag_[i]->frag_tab.Add(frag_[i + 1 - vertical]);
			if (i >= vertical+1 && frag_[i]->line == frag_[i - vertical-1]->line - 1) //3,1
			frag_[i]->frag_tab.Add(frag_[i - 1 - vertical]);
		}
		//counting problems and also refactorizing them periodicaly to make map more smooth
		/*
		while (problems != 0)
		{
			for (int i = 0;i < temp_num-vertical;i++)
			{
				if (FMath::Abs(frag_[i]->GetActorLocation().Z - frag_[i + vertical]->GetActorLocation().Z)> biomes[0]->height_diffrences)
				{
					problems++;
					if (frag_[i + 1]->GetActorLocation().Z > frag_[i]->GetActorLocation().Z)
					{
						FVector v = frag_[i + 1]->GetActorLocation();
						v.Z += 0.1 * biomes[0]->height_diffrences;
						frag_[i + 1]->SetActorLocation(v);
					}
					if (frag_[i + vertical]->GetActorLocation().Z < frag_[i]->GetActorLocation().Z)
					{
						FVector v = frag_[i]->GetActorLocation();
						v.Z += 0.1 * biomes[0]->height_diffrences;
						frag_[i]->SetActorLocation(v);
					}
					
				}
				
			}
			UE_LOG(LogTemp, Warning, TEXT("problems solving..."));
		}
		*/
		UE_LOG(LogTemp, Warning, TEXT("problems solved!"));
		
	}
};
