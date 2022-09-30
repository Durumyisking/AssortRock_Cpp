#pragma once
#include "Common.h"
#include "Map.h"

class CStage
{
public:
	CStage();
	~CStage();

public:
	CMap* Load(STAGE_TYPE _eType, int _Stage);

private:
	CMap* m_pNewMap;
};

