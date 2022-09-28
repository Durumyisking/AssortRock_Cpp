#include "Wall.h"

CWall::CWall()
{
	m_vPos = Pos{ -1, -1 };
	m_wcRender = L'¢Ì';
	m_strName = L"Wall";
	m_eColor = WINCOLOR::DARK_YELLOW;
	m_eType = OBJ_TYPE::WALL;
}

CWall::CWall(Pos _vPos)
{
	m_vPos = _vPos;
	m_wcRender = L'¢Ì';
	m_strName = L"Wall";
	m_eColor = WINCOLOR::DARK_YELLOW;
	m_eType = OBJ_TYPE::WALL;
}

CWall::~CWall()
{
}

void CWall::Update()
{
}

void CWall::Render()
{
}
