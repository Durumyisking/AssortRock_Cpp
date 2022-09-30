#include "House.h"

CHouse::CHouse()
{
	m_vPos = Pos{ -1, -1 };
	m_wcRender = L'ขอ';
	m_strName = L"House";
	m_eColor = WINCOLOR::WHITE;
	m_eType = OBJ_TYPE::HOUSE;

}

CHouse::CHouse(Pos _vPos)
{
	m_vPos = _vPos;
	m_wcRender = L'ขอ';
	m_strName = L"House";
	m_eColor = WINCOLOR::WHITE;
	m_eType = OBJ_TYPE::HOUSE;

	m_vPrevPos.push_back(_vPos);
}


void CHouse::Update()
{
}

void CHouse::Render()
{
}
