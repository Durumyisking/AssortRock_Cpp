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
	// ���Ͻ�Ʈ�� ����� error�� 0 ��ȯ
	// assert�� 0���� ������� ���� !�ؼ� 0�϶� ���
	assert(!error);

	wchar_t buff[64] = L"";

	if (0 != fp)
	{
		for (int y = 0; y < 8; y++)
		{
			int idx = 0;
			// file �Է�
			fgetws(buff, 63, fp);

			for (int x = 0; x < 8; x++)
			{
				m_pMap->SetStage(y, x, buff[idx++]);
			}
			cout << endl;
		}


		// ������ ���� ���������� �ϵ�� �ݳ��ؾ���
		fclose(fp);
	}


	return false;
}
