#pragma once
#include "Common.h"
#include "Map.h"

class CStage
{
public:
	CStage();
	~CStage();

public:
	void SetMap(CMap* _pMap) { m_pMap = _pMap; }
	bool Load();



private:
	CMap* m_pMap;
};

