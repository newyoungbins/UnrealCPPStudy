// Fill out your copyright notice in the Description page of Project Settings.


#include "Student.h"
#include "Card.h"

UStudent::UStudent()
{
	// 값 설정.
	Name = TEXT("학생");

	// 카드 타입 설정.
	Card->SetCardType(ECardType::Student);
}
