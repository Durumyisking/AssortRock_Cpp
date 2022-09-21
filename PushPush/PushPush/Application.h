#pragma once
#include "Common.h"


// class CScene; // ���漱���� �����͸�!(�翬�� �����ʹ� �׳� 8����Ʈ¥�� �����ʹϱ� ���� ���󵵴�)
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
	bool Init(); // ���� �߸��Ǿ ��ȯ���� false�϶� �����ϱ����� bool ����
	void Update();
	void Rendering();
	void Destroy();

public:
	bool GetIsRunning() { return m_bIsRunning; }
	void SetIsRunning(bool _bIsRunning) { m_bIsRunning = _bIsRunning; }

public:
	void ChangeScene(SCENE_TYPE _eType);

private:
	// private �Լ��� �ҹ��ڷ� �̸� ������ ����
	void clear();

private:
	static CApplication* m_Instance;


private:
	bool m_bIsRunning;
	CScene* m_arrScene[static_cast<UINT>(SCENE_TYPE::END)];
	SCENE_TYPE m_eCurrentScene;

};

