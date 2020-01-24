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
	UPROPERTY(EditAnywhere, Category = "Activation")
		bool overterrain = 1;
	UPROPERTY(EditAnywhere, Category = "Activation")
		bool deepterrain = 1;
	UPROPERTY(EditAnywhere, Category = "Activation")
		int amplitude_structure = 10;
	UPROPERTY(EditAnywhere, Category = "Activation")
		bool rotation_smoothing = 1;
	
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
		int xx = 0;
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
				//Afragment* gg = w->SpawnActor<Afragment>(Class_, vec, rot); // for frontier generating
				frag_.Add(a);
				a->line = i;
				a->line_h = j;
				//UE_LOG(LogTemp, Warning, TEXT("Szczecin"));
				temp_ver += 120;
				int ccc;
				if (xx > 15)
				{
					ccc = FMath::FRandRange(biomes[0]->amplitude - 1, biomes[0]->amplitude * 3);
					xx = 0;
				}
				xx++;
				
				if (y < -ccc)
				{
					u = 1;
				}
				if (y > ccc)
				{
					u = -1;
				}
				
			}
			temp_ver = 0;
			temp_hor += 120;
		}
		int problems = 1;
		float temp_num = (horizontal * vertical)-1;
		
		for (int i = 0;i < temp_num;i++)
		{
			//"making" neightbours of block inside his tab
			// 1,1  2,1  3,1
 			// 2,1  XXX  3,2
			// 3,1  3,2  3,3
			if (i<temp_num&& frag_[i]->line == (frag_[i + 1]->line)) // 2,1 S
			{
			frag_[i]->frag_tab.Add(frag_[i+1]);
			}
			if (i >= 1 && frag_[i]->line == (frag_[i - 1]->line))  // 2,3 S
			{
			frag_[i]->frag_tab.Add(frag_[i - 1]);
			}
			if (i< temp_num-vertical&& frag_[i]->line == (frag_[i + vertical]->line-1)) //3,2 S
			{
			frag_[i]->frag_tab.Add(frag_[i + vertical]);
			}
			if (i < (temp_num - vertical) - 1 && frag_[i]->line == (frag_[i + vertical + 1]->line - 1)) //3,1 S
			{
				frag_[i]->frag_tab.Add(frag_[i + 1 + vertical]);
			}
			if (i < (temp_num - vertical) + 1 && frag_[i]->line == (frag_[i + vertical-1]->line - 1)) //3,2 S
			{ 
			frag_[i]->frag_tab.Add(frag_[i - 1+vertical]);
			}
			if (i >= vertical&& frag_[i]->line == (frag_[i - vertical]->line + 1)) //1,1
			{
			frag_[i]->frag_tab.Add(frag_[i - vertical]);
			}
			if (i >= vertical-1 && frag_[i]->line == (frag_[i -vertical+1]->line + 1)) // 2,1
			{
			frag_[i]->frag_tab.Add(frag_[i + 1 - vertical]);
			}
			if (i >= vertical+1 && frag_[i]->line == (frag_[i - vertical-1]->line + 1)) //3,1
			{
			frag_[i]->frag_tab.Add(frag_[i - 1 - vertical]);
			}
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
//		Afragment* temporary_frag;
			for (int i = 0;i <= amplitude_structure;i++)
			{
				if (deepterrain)
				{
				int temp_rad1 = FMath::FRandRange(0, vertical-1);
				int temp_rad2 = FMath::FRandRange(0, horizontal-1);
				for (int j = 0;j <= (horizontal * vertical)-1;j++)
				{
					if (frag_[j]->line == vertical && frag_[j]->line_h == horizontal)
					{ 
					FVector v = frag_[j]->GetActorLocation();
					v.Z += 0.6 * biomes[0]->height_diffrences;
					frag_[j]->SetActorLocation(v);
						for (int k = 0; k < sizeof(frag_[j]->frag_tab);k++)
						{
						FVector vv = frag_[j]->frag_tab[k]->GetActorLocation();
						vv.Z += 0.3 * biomes[0]->height_diffrences;
						frag_[j]->frag_tab[k]->SetActorLocation(v);
						}
					}
				}
				}
				if (overterrain)
				{
					int temp_rad1 = FMath::FRandRange(0, vertical - 1);
					int temp_rad2 = FMath::FRandRange(0, horizontal - 1);
					for (int j = 0;j <= (horizontal * vertical) - 1;j++)
					{
						if (frag_[j]->line == vertical && frag_[j]->line_h == horizontal)
						{
							FVector v = frag_[j]->GetActorLocation();
							v.Z -= 0.6 * biomes[0]->height_diffrences;
							frag_[j]->SetActorLocation(v);
							for (int k = 0; k < sizeof(frag_[j]->frag_tab);k++)
							{
								FVector vv = frag_[j]->frag_tab[k]->GetActorLocation();
								vv.Z -= 0.3 * biomes[0]->height_diffrences;
								frag_[j]->frag_tab[k]->SetActorLocation(v);
							}
						}
					}
				}
				if (rotation_smoothing)
				{
					for (int i = 0;i <= (horizontal * vertical) - 1;i++)
					{
					FRotator vvv = FRotator(0,0,0);
					float g = 0;
						if (i < temp_num && frag_[i]->line == frag_[i + 1]->line && frag_[i]->GetActorLocation().Z < frag_[i + 1]->GetActorLocation().Z) // 2,1 S
							g = FMath::Abs(frag_[i]->GetActorLocation().Z - frag_[i + 1 ]->GetActorLocation().Z) / 10;
							vvv += FRotator(0 ,0, -g);
						if (i >= 1 && frag_[i]->line == frag_[i - 1]->line && frag_[i]->GetActorLocation().Z < frag_[i - 1]->GetActorLocation().Z)  // 2,3 S
							g = FMath::Abs(frag_[i]->GetActorLocation().Z - frag_[i - 1 ]->GetActorLocation().Z) / 10;
							vvv += FRotator(0, 0, g);
						if (i < temp_num - vertical && (frag_[i]->line == frag_[i + vertical]->line - 1) && frag_[i]->GetActorLocation().Z < frag_[i + vertical]->GetActorLocation().Z) //3,2 S
							g = FMath::Abs(frag_[i]->GetActorLocation().Z - frag_[i + vertical  ]->GetActorLocation().Z) / 10;
							vvv += FRotator(g, 0, 0);
						if (i >= vertical && frag_[i]->line == (frag_[i - vertical]->line + 1)&& frag_[i]->GetActorLocation().Z < frag_[i - vertical]->GetActorLocation().Z) //1,1
							g = FMath::Abs(frag_[i]->GetActorLocation().Z - frag_[i - vertical  ]->GetActorLocation().Z) / 10;
							vvv += FRotator(-g, 0, 0);
						//more complicated - decent
						
						if (i >= vertical - 1 && frag_[i]->line == (frag_[i - vertical + 1]->line + 1)&& frag_[i]->GetActorLocation().Z < frag_[i - vertical+1]->GetActorLocation().Z) // 2,1
						{
							g = FMath::Abs(frag_[i]->GetActorLocation().Z - frag_[i - vertical + 1]->GetActorLocation().Z)/10;
							vvv += FRotator(-g, 0, -g);
						}
						if (i >= vertical + 1 && frag_[i]->line == (frag_[i - vertical - 1]->line + 1)&& frag_[i]->GetActorLocation().Z < frag_[i - vertical-1]->GetActorLocation().Z) //3,1
						{
							g = FMath::Abs(frag_[i]->GetActorLocation().Z - frag_[i - vertical -1 ]->GetActorLocation().Z) / 10;
							vvv += FRotator(-g, 0, g);
						}
						if (i < (temp_num - vertical) - 1 && frag_[i]->line == (frag_[i + vertical + 1]->line - 1)&& frag_[i]->GetActorLocation().Z < frag_[i + vertical+1]->GetActorLocation().Z) //3,1 S
						{
							g = FMath::Abs(frag_[i]->GetActorLocation().Z - frag_[i + vertical +  1]->GetActorLocation().Z) / 10;
							vvv += FRotator(g, 0, g);
						}
						if (i < (temp_num - vertical) + 1 && frag_[i]->line == (frag_[i + vertical - 1]->line - 1)&& frag_[i]->GetActorLocation().Z < frag_[i + vertical-1]->GetActorLocation().Z) //3,2 S
						{
							g = FMath::Abs(frag_[i]->GetActorLocation().Z - frag_[i + vertical -1 ]->GetActorLocation().Z) / 10;
							vvv += FRotator(g, 0, -g);
						}
					frag_[i]->SetActorRotation(vvv);
					}
				}
		}
	}
};
