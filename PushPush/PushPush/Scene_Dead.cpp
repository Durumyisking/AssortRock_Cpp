#include "Scene_Dead.h"
#include "Application.h"

CScene_Dead::CScene_Dead()
	: m_bt(0)
	, m_ct(0)
	, m_btRender(0)
{
}

CScene_Dead::~CScene_Dead()
{
}

void CScene_Dead::Init()
{
}

void CScene_Dead::Update()
{
	m_ct = time(NULL);

	if (5 <= m_ct - m_bt)
	{
		Sleep(1000);
		CApplication::GetInst()->SetIsRunning(false);
	}
}

void CScene_Dead::Render()
{
	if (1 <= m_ct - m_btRender)
	{
		system("cls");


		SetColor(WINCOLOR::DARK_RED);

		void* p = new int();

		srand((int)p);
		int x = rand() % 50;

		srand((int)p);
		int y = rand() % 20;

		_SetCursor(x, y + 1); wcout << L"¢¾¢¾¢¾¢¾¢¾¢¾¢¾¢¾¢¾¢¾¢¾¢¾¢¾¢¾" << endl;
		_SetCursor(x, y + 2); wcout << L"¢¾       GOOD             ¢¾" << endl;
		_SetCursor(x, y + 3); wcout << L"¢¾               BYE      ¢¾" << endl;
		_SetCursor(x, y + 4); wcout << L"¢¾¢¾¢¾¢¾¢¾¢¾¢¾¢¾¢¾¢¾¢¾¢¾¢¾¢¾" << endl;

		m_btRender = m_ct;

		delete p;
	}
}

void CScene_Dead::Destroy()
{
}

void CScene_Dead::Enter()
{
	system("cls");
	m_bt = time(NULL);
	m_btRender = time(NULL);
}

void CScene_Dead::Exit()
{
	system("cls");
}
