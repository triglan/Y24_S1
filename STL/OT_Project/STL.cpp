//----------------------------------------------------------
// 2024 STL 3.5 �� 9-10��		(1-1)
// ----------------------------------------------------------

#include <iostream>
#include "save.h"
#include <fstream>
#include <array>



using namespace std;

// ���� : "int100�����޸𸮱״������.txt"��
// int�� 100���� write �Լ��� ����Ͽ� ��ϵǾ� �ִ�.
// ������ binary ���� ���� ��ϵǾ���. 
// ���Ͽ� ��ϵ� int�� 100���� �޸𸮷� �о�� ��
// ȭ�鿡 �� ���� ����϶�.

int main()
{
	ifstream in("int100�����޸𸮱״������.txt", ios::binary );
	if (not in)
		exit(0);

	array<int, 100>a;

	in.read((char*)a.data(), 400);

	for (int num : a)
		cout << num << "\t";
	cout << endl;

	save("STL.cpp");
}
