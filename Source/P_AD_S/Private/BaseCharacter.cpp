// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "BaseCharacterStatus.h"
#include "BaseCharacterAbilitySystem.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_asc = CreateDefaultSubobject<UBaseCharacterAbilitySystem>(TEXT("AbilitySystemComponent"));
	_status = CreateDefaultSubobject<UBaseCharacterStatus>(TEXT("BaseStatus"));
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return _asc;
}

UBaseCharacterStatus* ABaseCharacter::GetStatus() const
{
	return _status;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitializeSyatus();

}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::InitializeSyatus()
{
	if (nullptr == _asc)
	{
		return;
	}

	if (nullptr == _defaultStatusEffect)
	{
		UE_LOG(LogTemp, Error, TEXT("캐릭터의 기본 스테이터스 이펙트가 존재하지 않음"), *GetName());

		return;
	}

	//어빌리티 컴포넌트의 context
	//_asc에 정보를 가져와서 이펙트에 필요한 정보를 만들고 이 정보를 가지고 이펙트에 어플라이해라
	auto context = _asc->MakeEffectContext();
	context.AddSourceObject(this);

	auto handle = _asc->MakeOutgoingSpec(_defaultStatusEffect, 0, context);
	if (handle.IsValid())
	{
		_asc->ApplyGameplayEffectSpecToTarget(*handle.Data.Get(), _asc);
	}
}

