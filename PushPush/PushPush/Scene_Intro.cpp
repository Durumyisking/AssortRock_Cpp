#include "Scene_Intro.h"
#include "Application.h"

CScene_Intro::CScene_Intro()
	: m_bt(0)
	, m_ct(0)
	, m_iLine(8)
	, m_iRendertext(0)
	, m_bIsTextChanged(false)
{
}

CScene_Intro::~CScene_Intro()
{
}

void CScene_Intro::Init()
{
	m_bt  = time(NULL);
}

void CScene_Intro::Update()
{
	m_ct = time(NULL);

	if (5 <= m_ct - m_bt)
	{
		if (!m_bIsTextChanged)
		{
			++m_iRendertext;
			m_bIsTextChanged = true;
			m_bt = m_ct;
		}
	}


	if (_kbhit())
	{
		char chInput = 0;
		chInput = _getch();

		switch (chInput)
		{
		case '\r':
			system("cls");
			CApplication::GetInst()->ChangeScene(SCENE_TYPE::TITLE);
			break;
		default:
			break;
		}
	}
}

void CScene_Intro::Render()
{
	system("cls");

	switch (m_iRendertext)
	{
	case 0:
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 6);		wcout << L"2023�� ���ѹα��� ������鿡�� ������ ������ �Ͼ�� �ִ�." << endl;
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 8);		wcout << L"   �� ������ �ٷ� ���� �������ʰ� ��� ���´ٴ� ���̴�." << endl;
		SetColor(WINCOLOR::DARK_YELLOW);
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 14);		wcout << L"				 Press Enter to Skip Intro				" << endl;

		m_bIsTextChanged = false;
		break;
	case 1:
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 5);		wcout << L"    ������ ������ �ִ� ��� ����ο� �ϼ������� �ǹ̰�" << endl;
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 8);		wcout << L"  ���� ������ ���� �귯��ġ�� �ִٴ� ��簡 �� �ö�Դ�." << endl;
		SetColor(WINCOLOR::DARK_YELLOW);
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 14);		wcout << L"				 Press Enter to Skip Intro				" << endl;
		m_bIsTextChanged = false;
		break;
	case 2:
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 7);		wcout << L"       ������ ������ ������ ��� �� �̾߱�����..." << endl;
		SetColor(WINCOLOR::DARK_YELLOW);
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 14);		wcout << L"				 Press Enter to Skip Intro				" << endl;
		m_bIsTextChanged = false;
		break;
	case 3:
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 6);		wcout << L"                ���� ���� �װ� ��������" << endl;
		SetColor(WINCOLOR::GREEN);
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 8);		wcout << L"       ��������� ���� ������ �������� �������� " << endl;
		SetColor(WINCOLOR::DARK_YELLOW);
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 14);		wcout << L"				 Press Enter to Skip Intro				" << endl;
		m_bIsTextChanged = false;
		break;
	case 4:
		CApplication::GetInst()->ChangeScene(SCENE_TYPE::TITLE);
	default:
		break;
	}

}

void CScene_Intro::Destroy()
{
}

void CScene_Intro::Enter()
{
	system("cls");
}

void CScene_Intro::Exit()
{
	system("cls");
}
