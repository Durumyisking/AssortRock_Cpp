#include "Common.h"
#include "Application.h"

//#include "MyVector.h"
//#include "MyList.h"
//#include "Pair.h"

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


// wchar_t* 동적할당 했던것들 작업을 vector로 바꿔준다.
// 맵 크기만큼의 우리 MapClass에 데이터를 동적할당한다.
// 각 Obj의 데이터 값에 따라서 각 오브젝트들을 동적할당해준다.
// ball house에 넣기
// ball house에 넣으면 집 반짝빤짞
// 스테이지 클리어하면 다음 스테이지로
// UI 점수판 (캐릭터 이동횟수)
// 최종 스테이지 저장해줬다가 다시 키면 그 스테이지에서 시작
// 배경음악
// 이동할때 비프음 (종류 여러개 있으니까 돌 밀때 집 넣을때 등등 다양하게 사용하자)