//----------------------------------------------------------
// 2024 STL 4.2 ȭ (5-2����)
//  
// callable type - ������ Ÿ���� �ִ�.
// ȣ�� ������ Ÿ���� ��ǥ�ϴ� Ÿ���� ������� - function
//	
// sort�� �� � �������� ���������� ��� sort �Լ����� �˷��ֳ�?
// 1. �Լ������͸� ���⳪��
// 2. ���ٸ� �����Ѵ� -> visual studio������ �Լ� ��ü ��� �ܾ� ����
// 3. () ������(FUNCTION CALL)�� �����ε��� Ŭ������ ��ü -> �Լ� ��ü
// 
// ----------------------------------------------------------

#include <iostream>
#include <array>
#include "save.h"
#include "String.h"
#include <algorithm>
using namespace std;

extern bool ����;

int main()
{			
	array<String, 5> a{ "aersbc", "cdef", "efghght", "rdsfsagaa", "tokbsdfsrlk"};
	//[����] sort�� ����Ͽ� a�� �����ϴ� string�� ������������ ������ �� ����϶�
	//���� = true;
	for (const String& s : a)
		sort(s.getMem(), s.getMem() + s.getLen());
	���� = false;

	cout << "���� �������� ���İ��" << endl;
	for (const String& s : a) ///&�� �ǹ̴� �������� ����� ��
		cout << s << endl;
	save("STL.cpp");
}
