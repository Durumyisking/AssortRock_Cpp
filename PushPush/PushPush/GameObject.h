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
	void SetPos(Vector2 _vec) { m_vPos = _vec; }
	void SetMap(CMap* _pMap);

	wchar_t GetRenderwc() const { return m_wcRender; }
	wstring GetName() const { return m_strName; }

	void move(DIR _eDir);
	void movecheck(CGameObject* _pCheck, DIR _eDir);

	WINCOLOR GetObjColor() const { return m_eColor; }

protected:
	CMap* m_pMap;
	Vector2 m_vPos;
	wchar_t m_wcRender;
	wstring  m_strName;
	WINCOLOR m_eColor;
};

