#include <iostream>

using namespace std;

// ���ڿ� ���� ���ϱ�
// strlen�Լ�
int myStrLen()
{
	int len = 0;
	char str[6] = "Hello";

	for (size_t i = 0; i < 6; ++i)
	{
		if (str[i] == '\0')	 // ���ڿ� �迭�� �ִ� null���ڸ� ������
		{
			len = i;
			// break; �ݺ����� �����ص��ǰ�
			return len; // �̰ɷ� �Լ� �����ص���
		}
	}
	return len;
}


// ���ڿ�
int main()
{
	// �츮�� ���� ��������
	// int arr[10] �̷��� �����ϵ�
	// ���ڰ� ������ ���� ���ڿ��� char str[256] = {'A', 'B', 'C'}; �̷��� ����
	// �׷��� ���ŷο�ϱ�
	char str[6] = "Hello"; // �̷��� �����Ѵ�.
	// �ٵ� Hello�� 5�����ε� �� ũ�⸦ 6���� �����ϳ���?
	// �������� ���ڿ��� ���� ������ '\0'(null) ���ڸ� �����ϱ� ����
	// ���� char str[6] ={'h', 'e', 'l', 'l', 'o', '\0'};�� ����

	// std�� �̷� Ű���嵵 ������ ���߿� ����~
	// std::string str2 = "ImHappy";

	




	return 0;
}