#include "GameObject.h"
#include "Map.h"

int	moveFlag;

CGameObject::CGameObject()
	: m_vPos() // vector2 �����ڿ��� �ʱ�ȭ ���༭ ���ص� �Ǵµ� �׳� �ϰ����� ���� �ϴ°�
	, m_pMap(nullptr)
	, m_wcRender(L'\0')
	, m_eColor(WINCOLOR::BLACK)
	, m_eType(OBJ_TYPE::END)
	, m_pMoveFlag(nullptr)
{
	m_pMoveFlag = &moveFlag;
	*m_pMoveFlag = 0;
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
	// ���� �����̸� �̵����� prev�� ��ġ �־���
	if (L"Ball" == GetName())
	{
		for (int i = 0; i < m_pMap->GetObj(OBJ_TYPE::BALL).size(); i++)
		{
			m_pMap->
				GetObj(OBJ_TYPE::BALL)[i]->
				m_vPrevPos.push_back(m_pMap->
					GetObj(OBJ_TYPE::BALL)[i]->
					GetPos());
		}
		*m_pMoveFlag = 1;
	}
	// player�� �����̸� �̵����� prev�� ��ġ �־���
	else if (L"Player" == GetName())
	{
		for (int i = 0; i < m_pMap->GetObj(OBJ_TYPE::PLAYER).size(); i++)
		{
			m_pMap->
				GetObj(OBJ_TYPE::PLAYER)[i]->
				m_vPrevPos.push_back(m_pMap->
					GetObj(OBJ_TYPE::PLAYER)[i]->
					GetPos());
		}

		// Flag�� 0�̸� ����ġ pushback
		if (0 == *m_pMoveFlag)
		{
			for (int i = 0; i < m_pMap->GetObj(OBJ_TYPE::BALL).size(); i++)
			{
				CGameObject* pTemp = m_pMap->GetObj(OBJ_TYPE::BALL)[i];
				pTemp->m_vPrevPos.push_back(pTemp->GetPos());
			}
		}
		*m_pMoveFlag = 0;
	}

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
}


int CGameObject::movecheck(int _x, int _y, DIR _eDir)
{
	CGameObject* pObject = m_pMap->GetObj_Move(_x, _y);

	// �̵���ĭ ��ĭ�̸� �̵��ϰ� �Լ� ����
	if (nullptr == pObject)
	{
		move(_eDir);
		return 0;
	}

	wstring name = pObject->GetName();

	int result = 0;
	// ����ĭ�� ���̸�
	if (L"Wall" == name)
	{
		Beep(300, 100);
		// �̵� ����
		return 1;
	}
	// ���̸�
	else if (L"Ball" == name)
	{
		switch (_eDir)
		{
		case DIR::UP:
			// ��ĭ �ƴϸ� ����ĭ�� �˻�
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