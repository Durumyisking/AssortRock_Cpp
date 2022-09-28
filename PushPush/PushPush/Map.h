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

	vector <vector<wchar_t>>  GetData() { return m_Data; }



private:
//	wchar_t** m_pWall;
	vector <vector<wchar_t>> m_Data;

	size_t		m_sizeY;
	size_t		m_sizeX;

	CPlayer* m_pPlayer;

	vector<CGameObject*> m_pGameObjects[static_cast<UINT>(OBJ_TYPE::END)];

};

