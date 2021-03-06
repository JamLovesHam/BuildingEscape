// No unauthorized reproduction of this source code will be tolerated.

#pragma once

#include "GameFramework/Actor.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(VisibleAnywhere)
	float Reach = 200.0f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	/// Ray-cast and grab/release what's in reach
	void Grab();
	void Release();
	// Find (assumed) attached physics handle
	void FindPhysicsHandleComponent();
	// Setup/Find (assumed) attached input component
	void FindInputComponent();
	// Return hit for first physics body in reach
	FHitResult GetFirstPhysicsBodyInReach() const;
	FVector GetReachLineStart() const;
	FVector GetReachLineEnd() const;


};
