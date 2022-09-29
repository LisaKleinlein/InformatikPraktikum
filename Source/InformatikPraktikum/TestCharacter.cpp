// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "TestActor.h"

// Sets default values
ATestCharacter::ATestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initialize the Camera Boom    
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));

	//Setup Camera Boom attachment to the Root component of the class
	CameraBoom->SetupAttachment(RootComponent);

	//Set the boolean to use the PawnControlRotation to true.
	CameraBoom->bUsePawnControlRotation = true;

	//Initialize the FollowCamera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));

	//Set FollowCamera attachment to the Camera Boom
	FollowCamera->SetupAttachment(CameraBoom);

	
}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bEnableClickEvents = true;
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bEnableMouseOverEvents = true;
}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	


	//Variables
	FActorSpawnParameters SpawnParams;
	
	FVector wLocation, wDirection;
	float DistanceAboveGround = 180.0f;
	FVector PlaneOrigin(0.0f, 0.0f, DistanceAboveGround);

	//Getting mouse location in regard of the world location
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->DeprojectMousePositionToWorld(wLocation, wDirection);
	
	FVector ActorWorldLocation = FMath::LinePlaneIntersection(wLocation, wLocation + wDirection, PlaneOrigin, FVector::UpVector);


	//Spawn Actor
	//SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	//GetWorld()->SpawnActor<ATestActor>(ActorToBeSpawned, ActorWorldLocation, FRotator::ZeroRotator, SpawnParams);
	
	
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATestActor::StaticClass(), FoundActors);
	for (int i = 0; i < FoundActors.Num(); i++)
	{
		FoundActors[i]->SetActorLocation(ActorWorldLocation);
		//Spawn Actor
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		GetWorld()->SpawnActor<ATestActor>(ActorToBeSpawned, ActorWorldLocation, FRotator::ZeroRotator, SpawnParams);

	}

}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	//PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

