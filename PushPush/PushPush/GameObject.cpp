#include "GameObject.h"
#include "Map.h"

CGameObject::CGameObject()
	: m_vPos() // vector2 �����ڿ��� �ʱ�ȭ ���༭ ���ص� �Ǵµ� �׳� �ϰ����� ���� �ϴ°�
	, m_pMap(nullptr)
	, m_wcRender(L'\0')
{
}


CGameObject::~CGameObject()
{
}

void CGameObject::Update()
{
}

void CGameObject::Render()
{
}

void CGameObject::SetMap(CMap* _pMap) { m_pMap = _pMap; }


void CGameObject::move(DIR _eDir)
{
	m_pMap->SetStage(m_vPos.iy, m_vPos.ix, L'��');

	switch (_eDir)
	{
	case DIR::UP:
		SetPos(Pos(m_vPos.ix, m_vPos.iy - 1));
		break;
	case DIR::DOWN:
		SetPos(Pos(m_vPos.ix, m_vPos.iy + 1));
		break;
	case DIR::LEFT:
		SetPos(Pos(m_vPos.ix - 1, m_vPos.iy));
		break;
	case DIR::RIGHT:
		SetPos(Pos(m_vPos.ix + 1, m_vPos.iy));
		break;
	case DIR::END:
		break;
	default:
		break;
	}
	m_pMap->SetStage(m_vPos.iy, m_vPos.ix, GetRenderwc());

}


void CGameObject::movecheck(wchar_t _wcCheck, DIR _eDir)
{
	wchar_t** WallData = m_pMap->GetWall();
	if (L'��' == _wcCheck)
	{
		return;
	}
	else if (L'��' == _wcCheck)
	{
		switch (_eDir)
		{
		case DIR::UP:
			if (L'��' == WallData[m_vPos.iy - 2][m_vPos.ix])
				return;
			m_pMap->GetObj(m_vPos.ix, m_vPos.iy - 1)->movecheck(WallData[m_vPos.iy - 2][m_vPos.ix], _eDir);
			break;
		case DIR::DOWN:
			if (L'��' == WallData[m_vPos.iy + 2][m_vPos.ix])
				return;
			m_pMap->GetObj(m_vPos.ix, m_vPos.iy + 1)->movecheck(WallData[m_vPos.iy + 2][m_vPos.ix], _eDir);
			break;
		case DIR::LEFT:
			if (L'��' == WallData[m_vPos.iy][m_vPos.ix - 2])
				return;
			m_pMap->GetObj(m_vPos.ix - 1, m_vPos.iy)->movecheck(WallData[m_vPos.iy][m_vPos.ix - 2], _eDir);
			break;
		case DIR::RIGHT:
			if (L'��' == WallData[m_vPos.iy][m_vPos.ix + 2])
				return;
			m_pMap->GetObj(m_vPos.ix + 1, m_vPos.iy)->movecheck(WallData[m_vPos.iy][m_vPos.ix + 2], _eDir);
			break;
		case DIR::END:
			break;
		default:
			break;
		}
		move(_eDir);
	}
	else
	{
		move(_eDir);
	}
}