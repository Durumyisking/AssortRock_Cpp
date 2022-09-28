#include "Map.h"
#include "Ball.h"
#include "House.h"
#include "Wall.h"

CMap::CMap()
	: m_Data{}
	, m_pPlayer(nullptr)
	, m_sizeX(0)
	, m_sizeY(0)

{
	//for (size_t i = 0; i < static_cast<UINT>(OBJ_TYPE::END); i++)
	//{
	//	memset(m_pGameObjects[i], 0, sizeof(CGameObject*) * 128);
	//}
}

CMap::CMap(int _ix, int _iy)
	: m_Data{}
	, m_pPlayer(nullptr)
	, m_sizeX(_ix)
	, m_sizeY(_iy)
{
	//for (size_t i = 0; i < static_cast<UINT>(OBJ_TYPE::END); i++)
	//{
	//	memset(m_pGameObjects, 0, sizeof(CGameObject*) * static_cast<UINT>(OBJ_TYPE::END));
	//}
	m_Data.resize(m_sizeY);
	for (int i = 0; i < m_sizeY; ++i)
	{
		m_Data[i].resize(m_sizeX);
	}

	for (int i = 0; i < _iy; ++i)
	{
		for (int j = 0; j < _ix; ++j)
		{
			m_Data[i][j] = L'\0';
		}
	}
}

CMap::~CMap()
{
	for (size_t i = 0; i < static_cast<UINT>(OBJ_TYPE::END); i++)
	{
		for (size_t j = 0; j < m_pGameObjects[i].size(); j++)
		{
			if (nullptr == m_pGameObjects[i][j])
			{
				delete m_pGameObjects[i][j];
				m_pGameObjects[i][j] = nullptr;
			}
		}
	}
}

void CMap::Init()
{
	for (UINT y = 0; y < m_sizeY; ++y)
	{
		for (UINT x = 0; x < m_sizeX; ++x)
		{
			CheckMap(x, y, m_Data[y][x]);
		}
	}
}

void CMap::Update()
{
	for (size_t i = 0; i < static_cast<UINT>(OBJ_TYPE::END); i++)
	{
		for (size_t j = 0; j < m_pGameObjects[i].size(); j++)
		{
			if (nullptr != m_pGameObjects[i][j])
			{
				m_pGameObjects[i][j]->Update();
			}
		}
	}
}

void CMap::Render()
{
	for (UINT y = 0; y < m_sizeY; ++y)
	{
		for (UINT x = 0; x < m_sizeX; ++x)
		{
			SetColor(WINCOLOR::DARK_YELLOW);
			_SetCursor(static_cast<short>(x * 2 + PRINT_GAP_X), static_cast<short>(y + 10));
			wcout << m_Data[y][x];
			// 현재 렌더링 위치가 Object 위치면			
			SetGameObject(x, y);

		}
	}
}

/** _ix와 _iy와 GameObject의 위치가 일치하면 GameObject를 배치합니다*/
void CMap::SetGameObject(UINT _ix, UINT _iy)
{

	for (size_t i = 0; i < static_cast<UINT>(OBJ_TYPE::END); i++)
	{
		for (size_t j = 0; j < m_pGameObjects[i].size(); j++)
		{
			if (nullptr != m_pGameObjects[i][j])
			{
				if ((m_pGameObjects[i][j]->GetPos().ix == _ix) && (m_pGameObjects[i][j]->GetPos().iy == _iy))
				{
					if (L"Player" == m_pGameObjects[i][j]->GetName())
					{
						SetColor(m_pGameObjects[i][j]->GetObjColor());
					}
					else if (L"Ball" == m_pGameObjects[i][j]->GetName())
					{
						SetColor(m_pGameObjects[i][j]->GetObjColor());
					}
					else if (L"House" == m_pGameObjects[i][j]->GetName())
					{
						SetColor(m_pGameObjects[i][j]->GetObjColor());
					}

					_SetCursor(static_cast<short>(_ix * 2 + PRINT_GAP_X), static_cast<short>(_iy + 10));
					wcout << m_pGameObjects[i][j]->GetRenderwc();
				}
			}
		}
	}
}

void CMap::SetStage(int _iy, int _ix, wchar_t _wcInput)
{
	m_Data[_iy][_ix] = _wcInput;
}

void CMap::CheckMap(int _iy, int _ix, wchar_t _wc)
{
	if (L'♡' == _wc)
	{
		m_pPlayer = new CPlayer();
		m_pPlayer->SetPos(Pos(_ix, _iy));
		m_pPlayer->SetMap(this);
		AddGameObject(m_pPlayer);
	}
	else if (L'●' == _wc)
	{
		CBall* pBall = new CBall(Pos(_iy, _ix));
		pBall->SetMap(this);
		AddGameObject(pBall);
	}
	else if (L'♨' == _wc)
	{
		CHouse* pHouse = new CHouse(Pos(_iy, _ix));
		pHouse->SetMap(this);
		AddGameObject(pHouse);
	}
	else if (L'▩' == _wc)
	{
		CWall* pWall = new CWall(Pos(_iy, _ix));
		pWall->SetMap(this);
		AddGameObject(pWall);
	}
}



void CMap::AddGameObject(CGameObject* _pGameObj)
{
	if (nullptr != _pGameObj)
	{
		m_pGameObjects[static_cast<UINT>(_pGameObj->GetType())].push_back(_pGameObj);
	}
}

CGameObject* CMap::GetObj(int _ix, int _iy)
{
	for (size_t i = 0; i < static_cast<UINT>(OBJ_TYPE::END); i++)
	{
		for (size_t j = 0; j < m_pGameObjects[i].size(); j++)
		{
			if (nullptr != m_pGameObjects[i][j])
			{
				if (_ix == m_pGameObjects[i][j]->GetPos().ix && _iy == m_pGameObjects[i][j]->GetPos().iy)
					return m_pGameObjects[i][j];
			}
		}
	}
	return nullptr;
}


