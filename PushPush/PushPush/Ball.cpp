#include "Ball.h"

CBall::CBall()
{
	m_vPos = Pos{ -1, -1 };
	m_wcRender = L'¡Ü';
}

CBall::CBall(Pos _vPos)
{
	m_vPos = _vPos;
	m_wcRender = L'¡Ü';
}

CBall::~CBall()
{
}

void CBall::Update()
{
}

void CBall::Render()
{
}
