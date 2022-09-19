#include "Player.h"


CPlayer::CPlayer(int _iLevel)
	: status({5, 5 ,5, _iLevel})
{
}

void CPlayer::PrintLevel()
{
	std::cout << status.iLevel << std::endl;
}

void CPlayer::SetLevel(int _iLevel)
{
	this->status.iLevel = _iLevel;
}
