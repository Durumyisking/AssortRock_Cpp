#include "Scene_Ending.h"
#include "Application.h"

CScene_Ending::CScene_Ending()
	: m_bt(0)
	, m_ct(0)
	, m_iLine(8)
	, m_iRendertext(0)
	, m_bIsTextChanged(false)
{
}

CScene_Ending::~CScene_Ending()
{
}

void CScene_Ending::Init()
{

}

void CScene_Ending::Update()
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
			CApplication::GetInst()->ChangeScene(SCENE_TYPE::DEAD);
			break;
		default:
			break;
		}
	}
}

void CScene_Ending::Render()
{
	system("cls");

	if (STAGE_TYPE::EASY == g_eCurrentDifficulty)
	{
		switch (m_iRendertext)
		{
		case 1:
			_SetCursor(PRINT_GAP_X - 14, m_iLine + 6);		wcout << L"���� ���ѹα��� �ִ� ��� ������� Ʋ��Ҵ�." << endl;
			_SetCursor(PRINT_GAP_X - 14, m_iLine + 8);		wcout << L"�� ��� �������� �Ͼ�� ȫ���� ���߰� �Ǿ���." << endl;
			SetColor(WINCOLOR::DARK_YELLOW);
			_SetCursor(PRINT_GAP_X - 14, m_iLine + 14);		wcout << L"				 Press Enter to Skip Ending				" << endl;

			m_bIsTextChanged = false;
			break;
		case 2:
			_SetCursor(PRINT_GAP_X - 14, m_iLine + 5);		wcout << L"    ������ ������� ��� ���̻� ���� �� �� ����." << endl;
			SetColor(WINCOLOR::DARK_YELLOW);
			_SetCursor(PRINT_GAP_X - 14, m_iLine + 14);		wcout << L"				 Press Enter to Skip Ending				" << endl;
			m_bIsTextChanged = false;
			break;
		case 3:
			SetColor(WINCOLOR::DARK_RED);
			_SetCursor(PRINT_GAP_X - 14, m_iLine + 5);		wcout << L"               Sad Ending..." << endl;
			SetColor(WINCOLOR::DARK_YELLOW);
			_SetCursor(PRINT_GAP_X - 14, m_iLine + 14);		wcout << L"				 Press Enter to Skip Ending				" << endl;
			m_bIsTextChanged = false;
			break;
		case 4:
			CApplication::GetInst()->ChangeScene(SCENE_TYPE::DEAD);
		default:
			break;
		}
	}
	else if (STAGE_TYPE::HARD == g_eCurrentDifficulty)
	{
		switch (m_iRendertext)
		{
		case 1:
			_SetCursor(PRINT_GAP_X - 14, m_iLine + 6);		wcout << L"���� ���ѹα��� �ִ� ��� ������� Ʋ��Ҵ�." << endl;
			_SetCursor(PRINT_GAP_X - 14, m_iLine + 8);		wcout << L"�� ��� �������� �Ͼ�� ȫ���� ���߰� �Ǿ���." << endl;
			SetColor(WINCOLOR::DARK_YELLOW);
			_SetCursor(PRINT_GAP_X - 14, m_iLine + 14);		wcout << L"				 Press Enter to Skip Ending				" << endl;

			m_bIsTextChanged = false;
			break;
		case 2:
			_SetCursor(PRINT_GAP_X - 14, m_iLine + 5);		wcout << L"    ���� �� ���θ� ũ�� �������־���.." << endl;
			_SetCursor(PRINT_GAP_X - 14, m_iLine + 8);		wcout << L"  �� ��� ȥ�� ���� �� �� ���� ��ŭ�� ���¸� Ÿ���� �޾Ҵ�." << endl;
			SetColor(WINCOLOR::DARK_YELLOW);
			_SetCursor(PRINT_GAP_X - 14, m_iLine + 14);		wcout << L"				 Press Enter to Skip Ending				" << endl;
			m_bIsTextChanged = false;
			break;
		case 3:
			SetColor(WINCOLOR::SKY_BLUE);
			_SetCursor(PRINT_GAP_X - 14, m_iLine + 7);		wcout << L"                      ��Happy Ending��" << endl;
			SetColor(WINCOLOR::DARK_YELLOW);
			_SetCursor(PRINT_GAP_X - 14, m_iLine + 14);		wcout << L"				 Press Enter to Skip Ending				" << endl;
			m_bIsTextChanged = false;
			break;
		case 4:
			CApplication::GetInst()->ChangeScene(SCENE_TYPE::DEAD);
		default:
			break;
		}
	}
}

void CScene_Ending::Destroy()
{
}

void CScene_Ending::Enter()
{
	system("cls");
	m_bt = time(NULL);
}

void CScene_Ending::Exit()
{
	system("cls");
}
