// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class ZELTINA_UNREALCPP_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Speed = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MoveHeight = 200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SpinSpeed = 100.0f;
	float CosSpeed = 0.0f;
	float Height = 0.0f;

	bool GoingUp = true;


protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> BodyMesh = nullptr;
	//UStaticMeshComponent* BodyMesh = nullptr;

};
