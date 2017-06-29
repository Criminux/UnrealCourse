// Copyright Sebastian Bos 2017

#include "OpenDoor.h"
#include "Gameframework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UOpenDoor::OpenDoor()
{
	AActor *Owner = GetOwner();
	
	FRotator doorRotation = FRotator(0.0f, 70.0f, 0.0f);

	Owner->SetActorRotation(doorRotation);
	
	return;
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

}



// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume 
	if(PressurePlate->IsOverlappingActor(ActorThatOpens))
	{	
		OpenDoor();
	}
		
}

