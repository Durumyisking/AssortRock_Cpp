#include "Common.h"
#include "Application.h"

//#include "MyVector.h"
//#include "MyList.h"
//#include "Pair.h"

/*
	게임 구동 순서
	init -> while(update -> rendering) -> end
*/

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif


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


	// memory leak check
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	const char* str = DBG_NEW char[20];
	delete[] str;
	str = nullptr;

	return 0;
}

// 스테이지 클리어하면 다음 스테이지로
// UI 점수판 (캐릭터 이동횟수)
// 최종 스테이지 저장해줬다가 다시 키면 그 스테이지에서 시작
// 배경음악
// 이동할때 비프음 (종류 여러개 있으니까 돌 밀때 집 넣을때 등등 다양하게 사용하자)