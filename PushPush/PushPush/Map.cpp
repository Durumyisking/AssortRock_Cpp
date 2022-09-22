#include "Map.h"

CMap::CMap()
	: m_pWall(nullptr)
	, m_pPlayer(nullptr)
	, m_sizeX(0)
	, m_sizeY(0)

{
	memset(m_pGameObjects, 0, sizeof(CGameObject*) * 128);
}

CMap::CMap(int _ix, int _iy)
	: m_pWall(nullptr)
	, m_pPlayer(nullptr)
	, m_sizeX(_ix)
	, m_sizeY(_iy)
{
	memset(m_pGameObjects, 0, sizeof(CGameObject*) * 128);

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
	for (size_t i = 0; i < 128; i++)
	{
		if (nullptr == m_pGameObjects[i])
		{
			delete m_pGameObjects[i];;
			m_pGameObjects[i] = nullptr;
		}
	}


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

void CMap::Update()
{
	for (size_t i = 0; i < 128; i++)
	{
		m_pGameObjects[i]->Update();
	}
}

void CMap::Render()
{
	for (UINT y = 0; y < m_sizeY; ++y)
	{
		for (UINT x = 0; x < m_sizeX; ++x)
		{
			SetColor(WINCOLOR::DARK_YELLOW);
			_SetCursor(static_cast<short>(x * 2 + 19), static_cast<short>(y + 10));
			wcout << m_pWall[y][x];
			// 현재 렌더링 위치가 Object 위치면			
			SetGameObject(x, y);
			
		}
	}
}

/** _ix와 _iy와 GameObject의 위치가 일치하면 GameObject를 배치합니다*/
void CMap::SetGameObject(UINT _ix, UINT _iy)
{
	for (size_t i = 0; i < 128; i++)
	{
		if (nullptr != m_pGameObjects[i])
		{
			if ((m_pGameObjects[i]->GetPos().ix == _ix) && (m_pGameObjects[i]->GetPos().iy == _iy))
			{
				SetColor(WINCOLOR::VIOLET);
				_SetCursor(static_cast<short>(_ix * 2 + 19), static_cast<short>(_iy + 10));
				wcout << m_pGameObjects[i]->GetRenderwc();
			}
		}
	}
}

void CMap::SetStage(int _iy, int _ix, wchar_t _wcInput)
{
	m_pWall[_iy][_ix] = _wcInput;
}



void CMap::AddGameObject(CGameObject* _pGameObj)
{
	for (size_t i = 0; i < 128; i++)
	{
		if (nullptr == m_pGameObjects[i])
		{
			m_pGameObjects[i] = _pGameObj;
		}
	}
}


