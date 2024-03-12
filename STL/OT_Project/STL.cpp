//----------------------------------------------------------
// 2024 STL 3.5 �� 9-10��		(1-1)
// ----------------------------------------------------------

#include <iostream>
#include "save.h"
#include <array>
#include <print>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;

	
int main()
{
	//���� : int 100���� �����ϴµ� �޸� bit���� �״�� ��������.
	//int 100�� = sizeof(int) * 100 = 400 bytes

	array<int, 100>a{};

	iota(a.begin(), a.end(), 1);

	ofstream out{ "int100�����޸𸮱״������.txt", ios::binary };
	//�ο췹�� i/o�� ����Ѵ�.
	out.write( (const char*)(a.data()), a.size() * sizeof(int)); // �꺸�� ���� �ڵ�� ����. io ��ġ���� �����͸� ��ȯ��.

	//401����Ʈ�� ������ ��? OS�� �߰��� �����߱� �����̾�
	//ofstream out���� txt���Ϸ� �� ���� ������ io�� ����Ѽ��� ����Ʈ�� ��ȯ�ϸ鼭
	//����Ʈ�� �þ��. ios::binary�� ����Ʈ ��ȯ ���Ѵٰ� �˷��ָ� 400����Ʈ �״�� ���´�
	

	save("STL.cpp");
}
