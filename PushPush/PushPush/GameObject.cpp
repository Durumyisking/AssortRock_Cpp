#include "GameObject.h"

CGameObject::CGameObject()
	: m_vPos() // vector2 생성자에서 초기화 해줘서 안해도 되는데 그냥 일관성을 위해 하는것
	, m_wcRender(L'\0')
{
}

CGameObject::~CGameObject()
{
}
