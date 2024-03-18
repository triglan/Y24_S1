//----------------------------------------------------------
// 2024 STL 3.5 �� 9-10��
// 24-03-18 
// ���� ������ �޸� ���� - STACK CODE DATA Free store(Heap)
// ----------------------------------------------------------

#include <iostream>
#include "save.h"
#include <fstream>
#include <algorithm>
#include <array>
using namespace std;

//[����] eclass�� ���� ���� ������ �ִ�. ������ binary���� ����ߴ�.
//���⿡�� class Dog ��ü 100�� ���ϵǾ� �ִ�. write�Լ��� ����Ͽ� ����Ͽ���.
//class Dog�� ����� ������ ����.
//������ �о� num���� ���� ū dog��ü�� ȭ�鿡 ����϶�
//[����] -->	���⿡�� �� �� ���� �𸣴� class Dog ��ü�� write�ߴ�.
//[2] class Dog ��ü 100�� ��ϵǾ� �ִ�.
//[3] 1000�̸��� Dog ��ü�� ���� ����ض�.

class Dog {
	char c;
	int num;

public:
	int getNum() const {
		return num;
	}

	void show() const {
		cout << "char - " << c << ", num - " << num << endl;
	}

};

int main()
{
	//���̳ʸ��� ���� �ʾҴµ��� ���������� ����Ǹ鼭 �������� ��ó�� ���̱⿡ �����ؾ� �ȴ�
	//�� ������ ��� ��ϵǾ� �ִ��� binary ����ض�.
	ifstream in{ "����", ios::binary};
	if (not in) {
		cout << "������ �� �� ����" << endl;
		return 0;
	}
	array<Dog, 100> dogs;
	in.read((char*)&dogs, sizeof(Dog) * 100);
		
	//1000�̸��� dog�� ����ϱ� ���� count ���
	int cnt = count_if(dogs.begin(), dogs.end(), [](const Dog& dog) {
		return dog.getNum() % 2; // Ȧ�� �� �� ��, ¦�� �� �� ����
		});
	cout << "���� 1000 �̸��� Dog�� ���� - " << cnt << endl;
	save("STL.cpp");
}