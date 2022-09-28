#include "Ball.h"
#include "Map.h"

CBall::CBall()
	: m_bIsHome(false)
{
	m_vPos = Pos{ -1, -1 };
	m_wcRender = L'¡Ü';
	m_strName = L"Ball";
	m_eColor = WINCOLOR::DARK_BLUE;
	m_eType = OBJ_TYPE::BALL;
}

CBall::CBall(Pos _vPos)
{
	m_vPos = _vPos;
	m_wcRender = L'¡Ü';
	m_strName = L"Ball";
	m_eColor = WINCOLOR::DARK_BLUE;
	m_eType = OBJ_TYPE::BALL;
}

CBall::~CBall()
{
}

void CBall::Update()
{
	CGameObject* pCheckObj = m_pMap->GetObj(m_vPos.ix, m_vPos.iy);

	if (L"House" == pCheckObj->GetName())
	{
		m_bIsHome = true;
	}
	else
	{
		m_bIsHome = false;
	}

	if (m_bIsHome)
	{
		m_eColor = (static_cast<WINCOLOR>(rand() % 15));
		m_wcRender = L'¢Í';
	}
	else
	{
		m_eColor = WINCOLOR::DARK_BLUE;
		m_wcRender = L'¡Ü';
	}
}

void CBall::Render()
{
	
}
