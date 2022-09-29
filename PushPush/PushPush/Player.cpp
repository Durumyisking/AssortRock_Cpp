#include "Player.h"
#include "Map.h"

CPlayer::CPlayer()
{
	m_wcRender = L'��';
	m_strName = L"Player";
	m_eColor = WINCOLOR::VIOLET;
	m_eType = OBJ_TYPE::PLAYER;
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
			movecheck(m_vPos.ix, m_vPos.iy - 1, DIR::UP);
			break;
		case 'S': case 's':
			movecheck(m_vPos.ix, m_vPos.iy + 1, DIR::DOWN);
			break;
		case 'A': case 'a':
			movecheck(m_vPos.ix - 1, m_vPos.iy, DIR::LEFT);
			break;
		case 'D': case 'd':
			movecheck(m_vPos.ix + 1, m_vPos.iy, DIR::RIGHT);
			break;

		default:
			break;
		}

	}
}




