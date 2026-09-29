#pragma once

#include "CoreMinimal.h"

// 전방선언.
class UStudent;

class CPPUNREAL_API FStudentManager : public FGCObject
{
public:
	FStudentManager(UStudent* InStudent)
		: SafeStudent(InStudent)
	{

	}

	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

	/** Overload this method to report a name for your referencer */
	virtual FString GetReferencerName() const override
	{
		return TEXT("FStudentManager");
	}

	UStudent* GetSutudent() const { return SafeStudent; }

private:
	UStudent* SafeStudent = nullptr;
};