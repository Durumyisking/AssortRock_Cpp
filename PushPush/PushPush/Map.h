#pragma once
#include "Common.h"
#include "Player.h"

#include "GameObject.h"

class CMap
{
public:
	CMap();
	CMap(int _ix, int _iy);
	~CMap();

public:
	void Init(wstring& _strWall);
	void Update();
	void Render();

	void SetPlayer(CPlayer* _pPlayer) { m_pPlayer = _pPlayer; }
	void SetGameObject(UINT _ix, UINT _iy);
	void SetStage(int _iy, int _ix, wchar_t _wcInput);
	void AddGameObject(CGameObject* _pGameObj);

	wchar_t** GetWall() { return m_pWall; }



private:
	wchar_t**	m_pWall;

	size_t		m_sizeY;
	size_t		m_sizeX;

	CPlayer*	m_pPlayer;

	CGameObject* m_pGameObjects[128];

};

