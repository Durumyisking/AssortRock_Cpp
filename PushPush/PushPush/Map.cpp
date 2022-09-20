#include "Map.h"

CMap::CMap()
	: m_Map()
{
}

CMap::~CMap()
{
}

void CMap::Init()
{
	for (size_t y = 0; y < SIZE_MAP_X; y++)
	{
		for (size_t x = 0; x < SIZE_MAP_X; ++x)
		{
			m_Map[y][x] = L'бр';
		}
	}
}

void CMap::Render()
{
	SetColor(WINCOLOR::DARK_YELLOW);
	for (size_t y = 0; y < SIZE_MAP_X; y++)
	{
		for (size_t x = 0; x < SIZE_MAP_X; ++x)
		{
			wcout << m_Map[y][x];
		}
		cout << endl;
	}
}
