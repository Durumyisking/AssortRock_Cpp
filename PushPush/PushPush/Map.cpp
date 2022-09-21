#include "Map.h"

CMap::CMap()
	: m_pWall(nullptr)
	, m_pPlayer(nullptr)
	, m_sizeX(0)
	, m_sizeY(0)

{
}

CMap::CMap(int _ix, int _iy)
	: m_pWall(nullptr)
	, m_pPlayer(nullptr)
	, m_sizeX(_ix)
	, m_sizeY(_iy)
{
	m_pWall = new wchar_t* [_iy];
	for (int i = 0; i < _iy; ++i)
	{
		m_pWall[i] = new wchar_t[_ix];
	}

	for (int i = 0; i < _iy; ++i)
	{
		for (int j = 0; j < _ix; ++j)
		{
			m_pWall[i][j] = L'\0';
		}
	}
}

CMap::~CMap()
{
	for (int i = 0; i < m_sizeY; ++i)
	{
		delete[] m_pWall[i];
	}
	delete[] m_pWall;

}

void CMap::Init(wstring& _strWall)
{
	int idx = 0;
	for (size_t y = 0; y < m_sizeY; y++)
	{
		for (size_t x = 0; x < m_sizeX; ++x)
		{
			m_pWall[y][x] = _strWall[idx++];
		}
	}
}

void CMap::Render()
{
	for (size_t y = 0; y < m_sizeY; ++y)
	{
		for (size_t x = 0; x < m_sizeX; ++x)
		{
			SetColor(WINCOLOR::DARK_YELLOW);
			_SetCursor(static_cast<short>(x * 2 + 19), static_cast<short>(y + 10));
			wcout << m_pWall[y][x];
			// 현재 렌더링 위치가 player 위치면
			if ((m_pPlayer->GetPos().ix == x) && (m_pPlayer->GetPos().iy == y))
			{
				SetColor(WINCOLOR::VIOLET);
				_SetCursor(static_cast<short>(x * 2 + 19), static_cast<short>(y + 10));
				wcout << m_pPlayer->GetRenderwc();
			}
		}
	}
}

void CMap::SetObj(Vector2 _vec, wchar_t _wc)
{
	m_pWall[_vec.iy][_vec.ix] = _wc;
}

