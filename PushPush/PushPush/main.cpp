#include "Application.h"

/*
	게임 구동 순서
	init -> while(update -> rendering) -> end
*/
CApplication application;

int main()
{

	CMyVector<int>* vec = new CMyVector<int>();
	for (int i = 0; i < 35; i++)
	{
		vec->push_back(i);
	}

	for (int i = 0; i < vec->size(); i++)
	{
	}


	setlocale(LC_ALL, "");


	application.GetInst()->Init();				//	1. init

	while (application.GetInst()->GetIsRunning())
	{
		application.GetInst()->Update();	//		2. update
		application.GetInst()->Rendering(); //		3. rendering
	}
	application.GetInst()->Destroy();		//		4. end
}
