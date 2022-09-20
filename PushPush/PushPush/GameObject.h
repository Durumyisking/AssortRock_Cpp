#pragma once
#include "Common.h"

class CGameObject
{
public:
	CGameObject();
	~CGameObject();

private:
	Vector2 m_vPos;
	char m_chRender;
};

