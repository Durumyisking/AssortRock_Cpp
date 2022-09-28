#include "House.h"

CHouse::CHouse()
{
	m_vPos = Pos{ -1, -1 };
	m_wcRender = L'ขอ';
	m_strName = L"House";
	m_eColor = WINCOLOR::WHITE;

}

CHouse::CHouse(Pos _vPos)
{
	m_vPos = _vPos;
	m_wcRender = L'ขอ';
	m_strName = L"House";
	m_eColor = WINCOLOR::WHITE;

}

CHouse::~CHouse()
{
}

void CHouse::Update()
{
}

void CHouse::Render()
{
}
