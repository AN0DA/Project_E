// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "fragment.generated.h"

UCLASS()
class PROJECTE_API Afragment : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Afragment();
	UPROPERTY(EditAnywhere, Category = "Neightbours")
		TArray<Afragment*> frag_tab;
	UPROPERTY(EditAnywhere, Category = "IDs")
		int line = 0;
		int line_h = 0;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
