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
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 6);		wcout << L"2023년 대한민국의 목욕탕들에서 기이한 현상이 일어나고 있다." << endl;
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 8);		wcout << L"   그 현상은 바로 물이 멈추지않고 계속 나온다는 것이다." << endl;
		SetColor(WINCOLOR::DARK_YELLOW);
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 14);		wcout << L"				 Press Enter to Skip Intro				" << endl;

		m_bIsTextChanged = false;
		break;
	case 1:
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 5);		wcout << L"    어제는 국내에 있는 모든 배수로와 하수구들은 의미가" << endl;
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 8);		wcout << L"  없을 정도로 물이 흘러넘치고 있다는 기사가 막 올라왔다." << endl;
		SetColor(WINCOLOR::DARK_YELLOW);
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 14);		wcout << L"				 Press Enter to Skip Intro				" << endl;
		m_bIsTextChanged = false;
		break;
	case 2:
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 7);		wcout << L"       물부족 국가가 들으면 울고 갈 이야기지만..." << endl;
		SetColor(WINCOLOR::DARK_YELLOW);
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 14);		wcout << L"				 Press Enter to Skip Intro				" << endl;
		m_bIsTextChanged = false;
		break;
	case 3:
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 6);		wcout << L"                당장 내가 죽게 생겼으니" << endl;
		SetColor(WINCOLOR::GREEN);
		_SetCursor(PRINT_GAP_X - 14, m_iLine + 8);		wcout << L"       목욕탕까지 공을 굴려서 수원지를 차단하자 " << endl;
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
