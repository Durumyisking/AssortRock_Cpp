#pragma once
#include "Common.h"
#include "Player.h"

class CMap
{
public:
	CMap();
	CMap(int _ix, int _iy);
	~CMap();

public:
	void Init(wstring& _strWall);
	void Render();
	void SetObj(Vector2 _vec, wchar_t _wc);

	void SetPlayer(CPlayer* _pPlayer) { m_pPlayer = _pPlayer; }

	wchar_t** GetWall() { return m_pWall; }

private:
	wchar_t**	m_pWall;

	size_t		m_sizeY;
	size_t		m_sizeX;

	CPlayer*	m_pPlayer;

};

