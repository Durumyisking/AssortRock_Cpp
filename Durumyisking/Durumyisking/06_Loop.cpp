#include <iostream>

// ��������
int gData = 0;

// std : standard
// std���̺귯���� std::�� �������ϰ� using Ű���带 ����� �׻� �����ϰڴ�.
using namespace std;

// namespace Ű����
namespace MyLib
{
	int Pos;
	int Dir;
}

int main()
{

	// for��
	int x = 0;
	for (x = 1; x < 10; ++x)
	{
		std::cout << "Hello World!\n";
		if (x == 5)
		{
			// �ݺ��� Ż��
			break;
		}
		if (x == 7)
		{
			// Ư�� ���ǿ��� ��ŵ
			continue;
		}
	}

	// while��
	int y = 0;
	while (y < 10)
	{
		std::cout << "Hello World!\n";
		y++;
	}

	// do - while��
	// ������ �����̾ do �ڵ�� ���� �ڵ�� �ѹ� ����
	// ������ ���̸� ���ѹݺ�
	int z = 0;
	do
	{
		std::cout << "Hello World!\n";
		z++;
	} while (z < 10);

	// ���� for��
	int arr[5] = {0,1,2,3,4};
	for (int indexValue : arr)
	{
		// �̷����ϸ� indexValue�� arr�� ���� �ε���0���� ��ȸ��
		cout << indexValue << endl;
	}


	// ���������� ��� ���� �� �Ȱ�����
	gData = 5;
	{
		gData = 8;
	}

	// namespace�� ���� ���̺귯�� ����
	int myDir = MyLib::Dir;



	return 0;
}