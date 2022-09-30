#include "Player.h"
#include "Map.h"

CPlayer::CPlayer()
	: m_iMove(0)
{
	m_wcRender = L'��';
	m_strName = L"Player";
	m_eColor = WINCOLOR::VIOLET;
	m_eType = OBJ_TYPE::PLAYER;
}
CPlayer::CPlayer(Pos _vPos)
	: m_iMove(0)
{
	m_vPos = _vPos;
	m_wcRender = L'��';
	m_strName = L"Player";
	m_eColor = WINCOLOR::VIOLET;
	m_eType = OBJ_TYPE::PLAYER;
	m_vPrevPos.push_back(_vPos);

}


void CPlayer::Update()
{
	inputprocess();
}

void CPlayer::Render()
{
}

void CPlayer::inputprocess()
{
	if (_kbhit())
	{
		char input = _getch();

		switch (input)
		{
		case 'W': case 'w':
			if (1 != movecheck(m_vPos.ix, m_vPos.iy - 1, DIR::UP))
				++m_iMove;
			Beep(500, 100);
			break;
		case 'S': case 's':
			if (1 != movecheck(m_vPos.ix, m_vPos.iy + 1, DIR::DOWN))
				++m_iMove;
			Beep(500, 100);
			break;
		case 'A': case 'a':
			if (1 != movecheck(m_vPos.ix - 1, m_vPos.iy, DIR::LEFT))
				++m_iMove;
			Beep(500, 100);
			break;
		case 'D': case 'd':
			if (1 != movecheck(m_vPos.ix + 1, m_vPos.iy, DIR::RIGHT))
				++m_iMove;
			Beep(500, 100);
			break;

		default:
			break;
		}

	}
}




