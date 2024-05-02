// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacterStatus.h"
#include "GameplayEffect.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"


void UBaseCharacterStatus::PreAttributeChange(const FGameplayAttribute& Attribute, float& newValue)
{

}

void UBaseCharacterStatus::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	//체력과 스테미나 모두 0보다 크고 max 보다 작게 세팅
	if (Data.EvaluatedData.Attribute == Get_healthAttribute())
	{
		Set_health(FMath::Clamp(Get_health(), 0.f, Get_maxHealth()));
	}
	else if (Data.EvaluatedData.Attribute == Get_staminaAttribute())
	{
		Set_stamina(FMath::Clamp(Get_health(), 0.f, Get_stamina()));
	}

}
