// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));	//	씬 컴포넌트 하나 만들기
	SetRootComponent(root);	// 루트로 지정

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));	// 스태틱 메시 컴포넌트 하나 만들기
	BodyMesh->SetupAttachment(root);	// root 아래에 붙이기







}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
	//BodyMesh->SetRelativeLocation(FVector(0, 0, 100));
	//BodyMesh->AddRelativeLocation
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Loc = BodyMesh->GetRelativeLocation();	// FVector 타입의 Loc 변수에 BodyMesh의 현재 위치를 저장

	BodyMesh->AddRelativeRotation(FRotator(0.0f, SpinSpeed * DeltaTime, 0.0f));	// BodyMesh의 회전 방향을 Z축을 기준으로 틱당 SpinSpeed만큼 회전 

	if (GoingUp)	// 계속 올라간다면
	{
		Loc.Z += DeltaTime * Speed;	//	Loc의 Z의 값이 DeltaTime * Speed만큼 더함
		BodyMesh->AddRelativeLocation(DeltaTime * Speed * FVector::UpVector);	// BodyMesh의 현재 위치를 DeltaTime * Speed * 위 방향으로 값을 더함
		if (MoveHeight <= Loc.Z)	// MoveHeight 보다 Loc의 Z 값이 커지거나 같아지면
		{
			GoingUp = false;	// 그만 올라가라
		}
	}
	else
	{
		Loc.Z -= DeltaTime * Speed;	// Loc의 Z의 값이 DeltaTime * Speed만큼 뺌
		BodyMesh->AddRelativeLocation(DeltaTime * Speed * FVector::DownVector);	// BodyMesh의 현재 위치를 DeltaTime * Speed * 아래 방향으로 값을 더함
		if (Loc.Z <= 0)	// Loc의 Z의 값이 0보다 작아지거나 같아지면
		{
			GoingUp = true;	// 다시 올라가라
		}
	}
	/*CosSpeed += DeltaTime * Speed;
	Height += FMath::Cos(CosSpeed) + 1;
	UE_LOG(LogTemp, Warning, TEXT("Height: %.3f"), Height);
	BodyMesh->SetRelativeLocation(Height * MoveHeight * FVector::ZAxisVector);*/


}

