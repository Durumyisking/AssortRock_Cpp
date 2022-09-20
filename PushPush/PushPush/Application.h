#pragma once
#include "Common.h"


// class CScene; // ���漱���� �����͸�!(�翬�� �����ʹ� �׳� 8����Ʈ¥�� �����ʹϱ� ���� ���󵵴�)
class CScene;

class CApplication
{

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

public:
	void ChangeScene(SCENE_TYPE _eType);


private:
	bool m_bIsRunning;
	CScene* m_arrScene[static_cast<UINT>(SCENE_TYPE::END)];
	SCENE_TYPE m_eCurrentScene;

};

