// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"



UMyGameInstance::UMyGameInstance()
{
	// 기본값 설정.
	// 생성자에서 설정하는 기본 값은 CDO 템플릿 객체에 저장됨.
	//SchoolName = TEXT("기본 학교");
}

void UMyGameInstance::Init()
{
	Super::Init();

	// 객체 생성.
	FStudentData RawDataSource(TEXT("정영빈"), 42);
	
	// 파일로 다루기 위해 경로 설정.
	// 프로젝트 경로/ Saved 경로 지정.
	const FString SavedPath = FPaths::Combine(FPlatformMisc::ProjectDir(), TEXT("Saved"));

	// 경로 출력.
	UE_LOG(LogTemp, Log, TEXT("저장할 파일 폴더: %s"), *SavedPath);

	// 직렬화 구간.
	{
		// 저장할 파일 이름.
		const FString RawDataFileName(TEXT("RawData.bin"));

		// 파일 이름을 포함한 최종 경로.
		FString RawDataAbsolutePath = FPaths::Combine(SavedPath, RawDataFileName);

		// 경로 출력 (테스트).
		UE_LOG(LogTemp, Log, TEXT("저장할 전체 파일 경로 : %s"), *RawDataAbsolutePath);

		// 경로 정리.
		FPaths::MakeStandardFilename(RawDataAbsolutePath);

		// 변경된 경로 출력.
		UE_LOG(LogTemp, Log, TEXT("저장할 전체 파일 경로 : %s"), *RawDataAbsolutePath);
	}

	// 오브젝트 직렬화.
	// 1. 직렬화 처리를 위한 아카이브 생성.

	// 언리얼 오브젝트 직렬화.
	StudentSrc = NewObject<UStudent>();
	StudentSrc->SetOrder(100);
	StudentSrc->SetName(TEXT("YoungBin"));
	{
		// 파일 이름.
		const FString& ObjectDataFileName(TEXT("ObjectData.bin"));

		// 최종 경로 설정.
		FString ObjectDataPath = FPaths::Combine(SavedPath, ObjectDataFileName);
		FPaths::MakeStandardFilename(ObjectDataPath);

		// 직렬화.
		// 1. 메모리 직렬화.
		TArray<uint8> Buffer;
		FMemoryWriter MemoryWriter(Buffer);
		// 오브젝트 직렬화.
		StudentSrc->Serialize(MemoryWriter);

		// 2. 파일에 기록.
		TUniquePtr<FArchive> FileWriter = TUniquePtr<FArchive>(IFileManager::Get().CreateFileWriter(*ObjectDataPath));

		if (FileWriter)
		{
			// 기록.
			*FileWriter << Buffer;

			// 파일 닫기.
			FileWriter->Close();
		}
	}
}