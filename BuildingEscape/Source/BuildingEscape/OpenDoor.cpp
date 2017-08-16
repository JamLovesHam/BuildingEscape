// No unauthorized reproduction of this source code will be tolerated.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#define OUT


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	if (!PressurePlate) 
	{
		UE_LOG(LogTemp, Error, TEXT("Missing component PressurePlate! Please instantiate in OpenDoor.cpp"))
	}
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume every frame
	if (GetTotalMassOfActorsOnPlate() >= DoorRequiredOpenMass)
	{
		OpenDoor();
	}
	else
	{
		CloseDoor();
	}
}

void UOpenDoor::OpenDoor()
{
	// Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
	OnOpenRequest.Broadcast();
	return;
}

void UOpenDoor::CloseDoor()
{
	// Owner->SetActorRotation(FRotator(0.0f, CloseAngle, 0.0f));
	OnCloseRequest.Broadcast();
	return;
}

float UOpenDoor::GetTotalMassOfActorsOnPlate() 
{
	float TotalMass = 0.0f;
	// find overlapping actors
	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	// Iterate through them adding their masses

		for (const auto* Actor : OverlappingActors)
		{
			// Adding masses of Components in the TriggerVolume
			TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		}

	return TotalMass;


}