#pragma once
#include "Common.h"

class CMap
{
public:
	CMap();
	~CMap();

public:
	void Init();
	void Render();

private:
	wchar_t m_Map[SIZE_MAP_Y][SIZE_MAP_X];


};

