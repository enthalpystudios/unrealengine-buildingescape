// EnthalpyStudios 2018

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UOpenDoor::OpenDoor() {
    AActor* Owner = GetOwner();
    // Create a Rotator
    FRotator NewRotation = FRotator(0.0f, 60.0f, 0.0f);
    
    // Set the door rotation
    Owner->SetActorRotation(NewRotation);
    UE_LOG(LogTemp, Warning, TEXT("Rotation is at %s"), *NewRotation.ToString())
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

    ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Pool the trigger volume
    if (PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens))
    {
       OpenDoor();
    }
}

