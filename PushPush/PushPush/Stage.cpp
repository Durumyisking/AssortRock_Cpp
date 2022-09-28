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
	// ���Ͻ�Ʈ�� ����� error�� 0 ��ȯ
	// assert�� 0���� ������� ���� !�ؼ� 0�϶� ���
	assert(!error);

	wchar_t buff[64] = L"";

	int mapX = 0;
	int mapY = 0;


	// file �Է�	 
	// ���� Xũ��
	wstring x = fgetws(buff, 63, fp);
	mapX = stoi(x);
	// ���� Yũ��
	wstring y = fgetws(buff, 63, fp);
	mapY = stoi(y);

	// ������ ������� ũ�⸦ ������ �� ����
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
		// ������ ���� ���������� �ϵ�� �ݳ��ؾ���
		fclose(fp);
	}


	return newMap;
}
