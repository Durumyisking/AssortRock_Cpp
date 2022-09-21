#pragma once
#include "Common.h"

class CGameObject
{
public:
	CGameObject();
	~CGameObject();

public:
	virtual void Update() = 0;

	Vector2 GetPos() const { return m_vPos; }
	void SetPos(Vector2 _vec) { m_vPos = _vec; }

	wchar_t GetRenderwc() const { return m_wcRender; }
	void SetRenderwc(wchar_t _wcRender) { m_wcRender = _wcRender; }


protected:
	Vector2 m_vPos;
	wchar_t m_wcRender;
};

