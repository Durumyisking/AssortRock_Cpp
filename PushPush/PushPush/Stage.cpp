#include "Stage.h"

CStage::CStage()
	:m_iCurrentStage(1)
{
}

CStage::~CStage()
{
}

CMap* CStage::Load()
{

	wstring strStage = to_wstring(m_iCurrentStage);
	wstring strStagePath = L"..\\Stage\\Stage";
	wstring strPathEnd = L".txt";
	strStagePath += strStage;
	strStagePath += strPathEnd;


	FILE* fp = nullptr;
	errno_t error = _wfopen_s(&fp, strStagePath.c_str(), L"rt,ccs=UTF-8");
	// 파일스트림 존재시 error에 0 반환
	// assert에 0들어가면 오류출력 따라서 !해서 0일때 통과
	assert(!error);

	wchar_t buff[64] = L"";

	int mapX = 0;
	int mapY = 0;


	// file 입력	 
	// 맵의 X크기
	wstring x = fgetws(buff, 63, fp);
	mapX = stoi(x);
	// 맵의 Y크기
	wstring y = fgetws(buff, 63, fp);
	mapY = stoi(y);

	// 위에서 만들어준 크기를 가지는 맵 생성
	CMap* newMap = new CMap(mapX, mapY);


	if (0 != fp)
	{
		for (int y = 0; y < 8; y++)
		{
			fgetws(buff, 63, fp);

			for (int x = 0; x < 8; x++)
			{
				newMap->SetStage(y, x, buff[x]);
			}
			cout << endl;
		}
		// 램으로 파일 가져왔으면 하드로 반납해야함
		fclose(fp);
	}


	return newMap;
}
