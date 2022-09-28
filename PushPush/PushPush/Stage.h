#pragma once
#include "Common.h"
#include "Map.h"

class CStage
{
public:
	CStage();
	~CStage();

public:
	CMap* Load();
	int GetCurrentStage() const { return m_iCurrentStage; };

private:
	int m_iCurrentStage;
};

