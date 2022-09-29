// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"
#include "InformatikPraktikum.h"
#include "Components/BoxComponent.h"
#include "GameFramework/PlayerController.h"


// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	//Code from the unreal engine docs for a quick start
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	FVector Location = GetActorLocation();
	FRotator Rotation = GetActorRotation();
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	GetWorld()->SpawnActor<AActor>(ActorToSpawn, Location, Rotation, SpawnParams);
	

	//GetWorld()->SpawnActor<AActor>(ActorToSpawn, Location, Rotation);
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);
	
	


	

	

}



