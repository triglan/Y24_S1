//----------------------------------------------------------
// 2024 STL 3.5 �� 9-10��		(1-1)
// ----------------------------------------------------------

#include <iostream>
#include "save.h"
#include <random>
#include <array>
using namespace std;

default_random_engine dre;
uniform_int_distribution<int> uidChar{ 'a','z' };
uniform_int_distribution uidNum{ 1, 99999 };

class Dog {
	char c{ (char)uidChar(dre) };
	int num{ uidNum(dre) };

public:
	Dog() {
		cout << "����Ʈ ����" << endl;
	}
	friend ostream& operator<<(ostream& os, const Dog& dog) {
		return os << "���� : " << dog.c << ", ���� : " << dog.num;
	}
};

int main()
{
	array<Dog, 100> dogs{};
	for (const Dog& dog : dogs)
		cout << dog << endl;

	//���� : dogs�� binary mode/write�� ���Ͽ� ����ض�.
	//��ϵ� ������ �о num���� ���� ū dog�� ã�� ȭ�鿡 ���

	save("STL.cpp");
}
