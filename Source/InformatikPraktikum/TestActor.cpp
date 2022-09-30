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

	//Get the Shape
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_SPhere"));
	
	
	//Adds the Mesh and sets the physics of the object
	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		VisualMesh->SetSimulatePhysics(true);
		VisualMesh->WakeRigidBody();
		//Slows the gravitational pull
		//VisualMesh->SetLinearDamping(20.0f);
		//
		VisualMesh->SetEnableGravity(false);
		VisualMesh->SetPhysicsLinearVelocity((FVector(0.f, 0.f, -1.0f) * 50000.f));

	}

	//Should get the Material
	//static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/../Content/StarterContent/Particles/Materials/M_Fire_SubUV.uasset"));
	
	//Would be to set the Material
	/*if (FoundMaterial.Succeeded())
	{
		StoredMaterial = FoundMaterial.Object;
		VisualMesh->SetMaterial(0,StoredMaterial);

	}*/
	//DynamicMaterialInst = UMaterialInstanceDynamic::Create(StoredMaterial, VisualMesh);
	//VisualMesh->SetMaterial(0, StoredMaterial);
	
	
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(10);
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);
	
	
}



