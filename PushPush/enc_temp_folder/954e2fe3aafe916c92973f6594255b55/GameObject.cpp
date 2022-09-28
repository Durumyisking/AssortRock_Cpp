#include "GameObject.h"
#include "Map.h"

CGameObject::CGameObject()
	: m_vPos() // vector2 생성자에서 초기화 해줘서 안해도 되는데 그냥 일관성을 위해 하는것
	, m_pMap(nullptr)
	, m_wcRender(L'\0')
	, m_eColor(WINCOLOR::BLACK)
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
	
	m_pMap->SetStage(m_vPos.iy, m_vPos.ix, L'ㅤ');

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


void CGameObject::movecheck(CGameObject* _pCheck, DIR _eDir)
{
	if (nullptr != _pCheck)
	{
		if (L"Wall" == _pCheck->GetName())
		{
			return;
		}
		else if (L"Ball" == _pCheck->GetName())
		{
			switch (_eDir)
			{
			case DIR::UP:
				if (L"Wall" == m_pMap->GetObj(m_vPos.ix, m_vPos.iy - 2)->GetName())
					return;
				_pCheck->movecheck(m_pMap->GetObj(m_vPos.ix, m_vPos.iy - 2), _eDir);
				break;
			case DIR::DOWN:
				if (L"Wall" == m_pMap->GetObj(m_vPos.ix, m_vPos.iy + 2)->GetName())
					return;
				_pCheck->movecheck(m_pMap->GetObj(m_vPos.ix, m_vPos.iy + 2), _eDir);
				break;
			case DIR::LEFT:
				if (L"Wall" == m_pMap->GetObj(m_vPos.ix - 2, m_vPos.iy)->GetName())
					return;
				_pCheck->movecheck(m_pMap->GetObj(m_vPos.ix - 2, m_vPos.iy), _eDir);
				break;
			case DIR::RIGHT:
				if (L"Wall" == m_pMap->GetObj(m_vPos.ix + 2, m_vPos.iy)->GetName())
					return;
				_pCheck->movecheck(m_pMap->GetObj(m_vPos.ix + 2, m_vPos.iy), _eDir);
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
	else
	{
		move(_eDir);
	}
}