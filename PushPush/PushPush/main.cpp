#include "Common.h"
#include "Application.h"
#include "MyVector.h"
#include "MyList.h"

/*
	게임 구동 순서
	init -> while(update -> rendering) -> end
*/


CApplication application;

int main()
{
	CMyList<int>* list = new CMyList<int>();
	for (int i = 0; i < 5; i++)
	{
		list->Push_Back(i);
	}


	for (CMyList<int>::iterator iter = list->begin(); iter != list->end(); )
	{	
		iter = list->erase(iter);
	}

	list->clear();

	setlocale(LC_ALL, "");

	application.GetInst()->Init();				//	1. init

	while (application.GetInst()->GetIsRunning())
	{
		application.GetInst()->Update();	//		2. update
		application.GetInst()->Rendering(); //		3. rendering
	}
	application.GetInst()->Destroy();		//		4. end
}
