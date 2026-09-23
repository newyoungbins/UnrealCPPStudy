// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Person.generated.h"

// 전방선언.
class UCard;

/**
 * 
 */
UCLASS()
class CPPUNREAL_API UPerson : public UObject
{
	GENERATED_BODY()
	
public:
	UPerson();

	// Getter/Setter.
	inline const FString& GetName() const { return Name; }
	inline void SetName(const FString& InName) { Name = InName; }

	FORCEINLINE UCard* GetCard() const { return Card; }
	FORCEINLINE void SetCard(UCard* InCard) { Card = InCard; }

protected:
	// 관리 받는 속성으로 선언.
	UPROPERTY()
	FString Name;

	// 카드 객체.
	UPROPERTY()
	TObjectPtr<UCard> Card;
};
