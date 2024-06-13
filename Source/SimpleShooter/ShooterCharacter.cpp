// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "Gun.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	this->_gun = this->GetWorld()->SpawnActor<AGun>(this->_gunBlueprint);
	this->GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);

	USkeletalMeshComponent* mesh = this->GetMesh();
	
	this->_gun->AttachToComponent(mesh, FAttachmentTransformRules::KeepRelativeTransform, TEXT("weapon_socket"));
	this->_gun->SetOwner(this);
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(this->_moveForwardAxisName, this, &AShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(this->_moveSidewaysAxisName, this, &AShooterCharacter::MoveSideways);
	PlayerInputComponent->BindAxis(this->_lookUpAxisName, this, &AShooterCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(this->_lookUpControllerAxis, this, &AShooterCharacter::LookUpController);
	PlayerInputComponent->BindAxis(this->_lookSidewaysAxisName, this, &AShooterCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(this->_lookSidewaysControllerAxis, this, &AShooterCharacter::LookSidewaysController);
	PlayerInputComponent->BindAction(this->_jumpActionKey, EInputEvent::IE_Pressed, this, &AShooterCharacter::JumpCallback);
	PlayerInputComponent->BindAction(this->_shootAction, EInputEvent::IE_Pressed, this, &AShooterCharacter::ShootCallback);
}

void AShooterCharacter::MoveForward(float axis)
{
	this->AddMovementInput(this->GetActorForwardVector() * axis);
}

void AShooterCharacter::MoveSideways(float axis)
{
	this->AddMovementInput(this->GetActorRightVector() * axis);
}

void AShooterCharacter::JumpCallback()
{
	UE_LOG(LogTemp, Log, TEXT("JUMPING!!"));
	this->Jump();
}

void AShooterCharacter::LookUpController(float axis)
{
	this->AddControllerPitchInput(axis * this->_lookUpControllerRate * this->GetWorld()->DeltaTimeSeconds);
}

void AShooterCharacter::LookSidewaysController(float axis)
{
	this->AddControllerYawInput(axis * this->_lookSidewaysControllerRate * this->GetWorld()->DeltaTimeSeconds);
}

void AShooterCharacter::ShootCallback()
{
	this->_gun->PullTrigger();
}