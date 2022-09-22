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
	void Init();
	void Update();
	void Render();

	void SetPlayer(CPlayer* _pPlayer) { m_pPlayer = _pPlayer; }
	CPlayer* GetPlayer() const { return m_pPlayer; }
	void SetGameObject(UINT _ix, UINT _iy);
	void SetStage(int _iy, int _ix, wchar_t _wcInput);
	void CheckMap(int _iy, int _ix, wchar_t _wc);
	void AddGameObject(CGameObject* _pGameObj);

	CGameObject* GetObj(int _ix, int _iy);

	wchar_t** GetWall() { return m_pWall; }



private:
	wchar_t**	m_pWall;

	size_t		m_sizeY;
	size_t		m_sizeX;

	CPlayer*	m_pPlayer;

	CGameObject* m_pGameObjects[128];

};

