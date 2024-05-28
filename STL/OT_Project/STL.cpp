//---------------------------------------------------------
// 2024 1�б� STL 5�� 27�� ������
//
// Unordered associative container
// - unordered�� �ǹ�
// - �޸� ������ ���?
// - ���� ���� String�� ����������?
// 
// 6�� 11�� ȭ����(15�� 2) - �⸻����
//---------------------------------------------------------
#include <iostream>
#include "save.h"
#include "string.h"
#include <unordered_set>

using namespace std;
extern bool ����;

int main()
{
	unordered_set<int> us{ 3, 1, 4, 2 };

	us.insert(7);//�����͸� �߰��� �����ϸ�..? 3 1 4 2 7 �� �ڿ� �پ��� ���� �ֳ� ��
	us.insert(10);//3 1 4 10 2 7 �� �̹��� �̷��� �߳�


	for (int num : us)
		cout << num << ' ';
	cout << endl;


	save("STL.cpp");
}

