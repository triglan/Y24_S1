//----------------------------------------------------------
// 2024 STL 3.5 �� 9-10��								(1-1)
//
// Visual Studio 17.9.0 �̻�, Release/x64
// Project �Ӽ�/std:c++ latest <== �̸����� �ֽ�, SDL �˻� - NO ����
// 
// ���б� ���Ǹ� �����ϴ� save �����
// ----------------------------------------------------------

#include <random>
#include <format>
#include <iostream>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 1000, 9999 };

// ���� ���� ū ���� ã�� ȭ�鿡 ����϶�
int main()
{
	int a[1000];
	
	for (int& num : a)
		num = uid(dre);

	for (int num : a)
		cout << format("{:8}", num);

	// ���� ū ���� ã�� ���α׷�
	int big{ numeric_limits<int>::min()}; // int�� ���� �� �ִ� ���� �ּ��� ��.
	for (int num : a) {
		if (big < num) {
			big = num;
		}
	}

	cout << endl << endl << "���� ū �� : " << big << endl;
	save("STL.cpp");
}
