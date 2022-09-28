#include "GameObject.h"
#include "Map.h"

CGameObject::CGameObject()
	: m_vPos() // vector2 생성자에서 초기화 해줘서 안해도 되는데 그냥 일관성을 위해 하는것
	, m_pMap(nullptr)
	, m_wcRender(L'\0')
	, m_eColor(WINCOLOR::BLACK)
	, m_eType(OBJ_TYPE::END)
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
//	m_pMap->SetStage(m_vPos.iy, m_vPos.ix, L'ㅤ');

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
//	m_pMap->SetStage(m_vPos.iy, m_vPos.ix, GetRenderwc());

}


int CGameObject::movecheck(int _x, int _y, DIR _eDir)
{
	CGameObject* pObject = m_pMap->GetObj_Move(_x, _y);

	// 이동할칸 빈칸이면 이동하고 함수 종료
	if (nullptr == pObject)
	{
		move(_eDir);
		return 0;
	}

	wstring name = pObject->GetName();

	int result = 0;
	// 다음칸이 벽이면
	if (L"Wall" == name)
	{
		// 이동 안함
		return 1;
	}
	// 공이면
	else if (L"Ball" == name)
	{
		switch (_eDir)
		{
		case DIR::UP:
			// 빈칸 아니면 다음칸도 검사
			result = pObject->movecheck(_x, _y - 1, _eDir);
			break;
		case DIR::DOWN:
			result = pObject->movecheck(_x, _y + 1, _eDir);
			break;
		case DIR::LEFT:
			result = pObject->movecheck(_x - 1, _y, _eDir);
			break;
		case DIR::RIGHT:
			result = pObject->movecheck(_x + 1, _y, _eDir);
			break;

		case DIR::END:
			break;
		default:
			break;
		}
		if (1 == result)
		{
			return 1;
		}
	}
	move(_eDir);
	return 0;
}