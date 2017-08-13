// No unauthorized reproduction of this source code will be tolerated.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
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

	// Poll the Trigger Volume every frame
	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) 
	{
		OpenDoor();
	}
	
}

void UOpenDoor::OpenDoor()
{
	// Find owning Actor
	AActor* Owner = GetOwner();
	// Create a rotator
	FRotator NewRotation = FRotator(0.0f, 60.0f, 0.0f);
	// Set the door rotation
	Owner->SetActorRotation(NewRotation);

}

