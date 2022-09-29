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
	CGameObject* GetObj_Move(int _ix, int _iy);

	UINT GetBallInHouseCount() const { return m_iBallInHouse; }
	void SetBallInHouseCount(int _iCount) { m_iBallInHouse = _iCount; }

	bool IsClear() const { return m_bIsClear; }

private:
//	wchar_t** m_pWall;
	vector <vector<wchar_t>> m_Data;

	size_t		m_sizeY;
	size_t		m_sizeX;

	CPlayer* m_pPlayer;

	UINT	m_iHouseCount;
	UINT	m_iBallInHouse;

	vector<CGameObject*> m_pGameObjects[static_cast<UINT>(OBJ_TYPE::END)];

	bool	m_bIsClear;

};

