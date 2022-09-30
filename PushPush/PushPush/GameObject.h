#pragma once
#include "Common.h"

class CMap;

class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();

public:
	virtual void Update();
	virtual void Render();

	Vector2 GetPos() const { return m_vPos; }
	Vector2 GetPrevPos() 
	{
		// �ʱ� ��ġ�� ������ġ return
		if (0 == m_vPrevPos.size())
		{
			return m_vPos;
		}
		// ���������� ������ ��ġ�� return
		Vector2 temp = m_vPrevPos[m_vPrevPos.size() - 1];
		m_vPrevPos.pop_back();
		return temp;	
	}
	void SetPos(Vector2 _vec) { m_vPos = _vec; }
	void SetMap(CMap* _pMap);

	wchar_t GetRenderwc() const { return m_wcRender; }
	wstring GetName() const { return m_strName; }

	void move(DIR _eDir);
	int movecheck(int _x, int _y, DIR _eDir);

	WINCOLOR GetObjColor() const { return m_eColor; }
	OBJ_TYPE GetType() const { return m_eType; }
protected:
	CMap* m_pMap;
	Vector2 m_vPos;
	vector<Vector2> m_vPrevPos;
	wchar_t m_wcRender;
	wstring  m_strName;
	WINCOLOR m_eColor;
	OBJ_TYPE m_eType;

private:
	int* m_pMoveFlag;
};

