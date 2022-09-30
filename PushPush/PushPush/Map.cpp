#include "Map.h"
#include "Ball.h"
#include "House.h"
#include "Wall.h"

#include "Application.h"

CMap::CMap()
	: m_Data{}
	, m_pPlayer(nullptr)
	, m_sizeX(0)
	, m_sizeY(0)
	, m_iHouseCount(0)
	, m_iBallInHouse(0)
	, m_bIsClear(false)
{

}

CMap::CMap(int _ix, int _iy)
	: m_Data{}
	, m_pPlayer(nullptr)
	, m_sizeX(_ix)
	, m_sizeY(_iy)
	, m_iHouseCount(0)
	, m_iBallInHouse(0)
	, m_bIsClear(false)
{
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
			if (nullptr != m_pGameObjects[i][j])
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
			// 현재 좌표에 객체로 생성할수 있는 모양 있으면 현재 좌표를 가지는 객체 생성
			CheckMap(x, y, m_Data[y][x]);
			
			m_Data[y][x] = L'　';
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

	if (m_iBallInHouse == m_iHouseCount)
	{
		m_bIsClear = true;
		CApplication::GetInst()->ChangeScene(SCENE_TYPE::CLEAR);
	}
}

void CMap::Render()
{
	for (UINT y = 0; y < m_sizeY; ++y)
	{
		for (UINT x = 0; x < m_sizeX; ++x)
		{
			SetColor(WINCOLOR::DARK_YELLOW);
			_SetCursor(static_cast<short>(x * 2 + PRINT_GAP_X +5), static_cast<short>(y + 10));
			// 공백은 계속 출력해줘야함
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

					_SetCursor(static_cast<short>(_ix * 2 + PRINT_GAP_X+5), static_cast<short>(_iy + 10));
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

void CMap::CheckMap(int _ix, int _iy, wchar_t _wc)
{
	if (L'♡' == _wc)
	{
		m_pPlayer = new CPlayer(Pos(_ix, _iy));
		m_pPlayer->SetMap(this);
		AddGameObject(m_pPlayer);
	}
	else if (L'●' == _wc)
	{
		CBall* pBall = new CBall(Pos(_ix, _iy));
		pBall->SetMap(this);
		AddGameObject(pBall);
	}
	else if (L'♨' == _wc)
	{
		++m_iHouseCount;
		CHouse* pHouse = new CHouse(Pos(_ix, _iy));
		pHouse->SetMap(this);
		AddGameObject(pHouse);
	}
	else if (L'▩' == _wc)
	{
		CWall* pWall = new CWall(Pos(_ix, _iy));
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

CGameObject* CMap::GetObj_Move(int _ix, int _iy)
{
	for (int i = static_cast<int>(OBJ_TYPE::END) - 1; i >= static_cast<int>(OBJ_TYPE::WALL); i--)
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


