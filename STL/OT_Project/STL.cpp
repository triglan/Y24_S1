//----------------------------------------------------------
// 2024 STL 4.15 ȭ (7-1����)
//  
// 4/23 �߰�����
// ----------------------------------------------------------

#include <iostream>
#include <vector>
#include "save.h"
#include "String.h"
using namespace std;
extern bool ����;

int main()
{
	vector<int> v{ 1,2,3,4,5,5,3,4,3,33 };
	
	//[����] v���� 3�� �����ϰ� ����϶�
	//�ʹ� ���� ����ϴ� �����̶� �̸��� �پ��ִ�
	//erase-remove idiom
	v.erase(remove(v.begin(), v.end(), 3), v.end());//���� ����Լ��� ���� �Լ�

	for (int num : v)
		cout << num << ' ';
	save("STL.cpp");
}