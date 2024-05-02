// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "BaseCharacter.generated.h"

UCLASS()
class P_AD_S_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	class UBaseCharacterStatus* GetStatus() const;

protected:
	UPROPERTY()
	class UBaseCharacterStatus* _status;
	UPROPERTY()
	class UAbilitySystemComponent* _asc;

	//게임 플레이 이펙트
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Status")
	TSubclassOf<class UGameplayEffect> _defaultStatusEffect;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void InitializeSyatus();
};
