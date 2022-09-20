#include "Common.h"
#include "Application.h"

/*
	게임 구동 순서
	init -> while(update -> rendering) -> end
*/


CApplication application;

int main()
{
	setlocale(LC_ALL, "");


	application.Init(); //				1. init

	while (application.GetIsRunning())
	{
		application.Update(); //		2. update
		application.Rendering(); //		3. rendering
	}
	application.Destroy(); //			4. end
}
