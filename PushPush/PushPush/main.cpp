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


	application.GetInst()->Init();				//	1. init

	while (application.GetInst()->GetIsRunning())
	{
		application.GetInst()->Update();	//		2. update
		application.GetInst()->Rendering(); //		3. rendering
	}
	application.GetInst()->Destroy();		//		4. end
}
