#pragma once
#include "Common.h"


// class CScene; // 전방선언은 포인터만!(당연함 포인터는 그냥 8바이트짜리 포인터니까 뭔지 몰라도댐)
class CScene;

class CApplication
{
// Singleton Pattern
public:
	static CApplication* GetInst()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new CApplication();
		}
		return m_Instance;
	}


public:
	CApplication();
	~CApplication();

public:
	bool Init(); // 무언가 잘못되어서 반환값이 false일때 종료하기위해 bool 선언
	void Update();
	void Rendering();
	void Destroy();

public:
	bool GetIsRunning() { return m_bIsRunning; }
	void SetIsRunning(bool _bIsRunning) { m_bIsRunning = _bIsRunning; }

public:
	void ChangeScene(SCENE_TYPE _eType);

private:
	// private 함수는 소문자로 이름 지으면 좋음
	void clear();

private:
	static CApplication* m_Instance;


private:
	bool m_bIsRunning;
	CScene* m_arrScene[static_cast<UINT>(SCENE_TYPE::END)];
	SCENE_TYPE m_eCurrentScene;

};

