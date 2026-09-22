// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init();

	//UE_LOG(LogTemp, Log, TEXT("Hello Unreal"));
	TCHAR LogCharArray[] = TEXT("Hello Unreal");
	UE_LOG(LogTemp, Log, TEXT("%s"), LogCharArray);

	FString LogCharString = LogCharArray;
	UE_LOG(LogTemp, Log, TEXT("%s"), *LogCharString);

	// 문자열 복사.
	TCHAR LogCharArrayWithSize[100] = {};
	FCString::Strncpy(LogCharArrayWithSize, *LogCharString, LogCharString.Len());

	UE_LOG(LogTemp, Log, TEXT("%s"), LogCharArrayWithSize);

	// 문자열 자르기.
	if (LogCharString.Contains(TEXT("unreal"), ESearchCase::IgnoreCase))
	{
		// 문자열을 검색해 시작 인덱스 얻기.
		int32 Index = LogCharString.Find(TEXT("unreal"), ESearchCase::IgnoreCase);
		FString EndString = LogCharString.Mid(Index);
		UE_LOG(LogTemp, Log, TEXT("%s"), *EndString);
	}

	// 문자열 나누기.
	FString Left, Right;
	if (LogCharString.Split(TEXT(" "), &Left, &Right))
	{
		UE_LOG(LogTemp, Log, TEXT("Split Test: %s / %s"), *Left, *Right);
	}

	// 문자열 조합.
	int32 IntValue = 40;
	float FloatValue = 3.141592f;

	FString FloatIntString = FString::Printf(TEXT("Int:%d, Float:%f"), IntValue, FloatValue);
	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString);

	// FName 특성 살펴보기 - 대소문자 구별하지 않음.
	FName Key1(TEXT("PELVEIS"));
	FName Key2(TEXT("PELVEIS"));

	UE_LOG(LogTemp, Log, TEXT("FName 비교 결과: %s"), (Key1 == Key2 ? TEXT("같음") : TEXT("다름")));
}
