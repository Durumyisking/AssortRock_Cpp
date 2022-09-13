#include <iostream>


using namespace std;

struct Person
{
	int height;
	int age;
	char* name;
};


int main()
{
	// dynamic allocator

	// 1. malloc

	// malloc(����Ʈ ũ��) ��ȯ�� void* 
	// void*�� �ܼ��ϰ� �ּҰ��� �����Ҷ� ���
	// void* p = malloc(4);
	int* p = (int*)malloc(4);
	*p = 100;

	int size = sizeof(int);

	Person a;
	// memset(������, ������, ũ��) -> �����Ϳ� �����ؼ� ũ�⸸ŭ �����͸� �ʱ�ȭ�����ְڴ�
	a.name = (char*)malloc(sizeof(char) * 10);
	memset(a.name, 0, sizeof(char) * 10); // a.name0�������� 10����Ʈ��ŭ 0���� �ʱ�ȭ�ϰڴ�.
	// �ٵ� �̰� ����� ��������?

	// calloc(count, �޸�ũ��) -> �޸�ũ��*count��ŭ 0�������� �ʱ�ȭ������
	a.name = (char*)calloc(10, sizeof(char));

	// �޸� ����
//	free(a.name);
	// �޸� ���Ҵ��Ϸ��� �޸� ������ �ٽ� �Ҵ��ؾ���

	// realloc(������, ������ũ��) �޸� ������ �ٷ� ���Ҵ� ����
	realloc(a.name, sizeof(char) * 10);

	// memcpy(������ ������, ������ ������, ũ��) -> ������ �����͸� ������ �������� 0������ ũ�⸸ŭ �޸� ����
	char babo[5] = "babo";
	memcpy(a.name, babo, 5); // -> a.name �� 0�� �ε����� babo�� 0���ε������� ���ʴ�� ä��


	free(a.name);

	free(p);


	// 2. new (c++)

	// new + �ڷ��� 
	int* ptr = new int; // �̷� ����

	int iarrSize = 0;
	cin >> iarrSize;
	int* pArr = new int[iarrSize]; // �̷� ���� �Է��Ѵ�� �迭 ������ �Ҵ�

	// �޸� ����
	delete ptr;
	delete[] pArr;




	// ����Ʈ�е� (������ ���� ���Ϳ�!)
	Person person; // ��� �� 12����Ʈ !? int int char�̸� 9����Ʈ�ݾƿ� !

	person.age = 0;
	person.height = 0;
	person.name = '\0';
	// person.age person.height person.name�� �����͸� �ֱ����� �����Ʈ�� �־���ұ� ����ϸ� ������ 3���ؾ��� 4 4 1
	// �� ����Ƚ���� ���̱� ���ؼ� �׳� ����ū���� 4����Ʈ��? �ϰ� �� 4����Ʈ�� �����ؼ� �־����

	return 0;
}