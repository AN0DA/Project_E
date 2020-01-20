
#include "world_generator.h"

// Sets default values
Aworld_generator::Aworld_generator()
{
	PrimaryActorTick.bCanEverTick = true;
}
	void Aworld_generator::BeginPlay()
	{
		Super::BeginPlay();
		Generate_common();
	}


// Called every frame
void Aworld_generator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

