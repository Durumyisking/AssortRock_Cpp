#include "Stage.h"

CStage::CStage()
	: m_pMap(nullptr)
{
}

CStage::~CStage()
{
}

bool CStage::Load()
{
	FILE* fp = nullptr;
	errno_t error = _wfopen_s(&fp, L"..\\Stage\\Stage01.txt", L"rt,ccs=UTF-8");
	// 파일스트림 존재시 error에 0 반환
	// assert에 0들어가면 오류출력 따라서 !해서 0일때 통과
	assert(!error);

	wchar_t buff[64] = L"";

	if (0 != fp)
	{
		for (int y = 0; y < 8; y++)
		{
			int idx = 0;
			// file 입력
			fgetws(buff, 63, fp);

			for (int x = 0; x < 8; x++)
			{
				m_pMap->SetStage(y, x, buff[idx++]);
			}
			cout << endl;
		}


		// 램으로 파일 가져왔으면 하드로 반납해야함
		fclose(fp);
	}


	return false;
}
