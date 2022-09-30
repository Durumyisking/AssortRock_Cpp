#include "Stage.h"

CStage::CStage()
	: m_pNewMap(nullptr)
{
}

CStage::~CStage()
{
}

CMap* CStage::Load(STAGE_TYPE _eType, int _Stage)
{

	wstring strStage = to_wstring(_Stage);
	wstring strStagePath;
	if (STAGE_TYPE::EASY == _eType)
	{
		strStagePath = L"..\\Stage\\Easy\\Stage";
	}
	else if (STAGE_TYPE::HARD == _eType)
	{
		strStagePath = L"..\\Stage\\Hard\\Stage";
	}
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
	m_pNewMap = new CMap(mapX, mapY);


	if (0 != fp)
	{
		for (int y = 0; y < mapY; y++)
		{
			fgetws(buff, 63, fp);

			for (int x = 0; x < mapX; x++)
			{
				m_pNewMap->SetStage(y, x, buff[x]);
			}
			cout << endl;
		}
		// ������ ���� ���������� �ϵ�� �ݳ��ؾ���
		fclose(fp);
	}


	return m_pNewMap;
}
