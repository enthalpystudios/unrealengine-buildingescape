// EnthalpyStudios 2018

#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
    UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"));
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get the player view point for this tick
    FVector Location;
    FRotator Rotation;
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
        OUT Location,
        OUT Rotation
    );
    
//    UE_LOG(LogTemp, Warning, TEXT("The location is at %s and Rotation is at %s"), *Location.ToString(), *Rotation.ToString());

    // Draw Red trace in the world to visualize
    FVector LineTraceEnd = Location + Rotation.Vector() * Reach;
    DrawDebugLine(GetWorld(), Location, LineTraceEnd, FColor(255, 0, 0), false, 0.f, 0.f, 2.f);
    
    // ray-cast out to reach distance
    
    // see what we hit
}

