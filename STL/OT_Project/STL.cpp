#include <iostream>
#include "save.h"
#include <random>
#include <array>
#include <fstream>
using namespace std;

default_random_engine dre;
uniform_int_distribution<int> uidChar{ 'a','z' };
uniform_int_distribution uidNum{ 1, 99999 };

class Dog {
	char c{ (char)uidChar(dre) };
	int num{ uidNum(dre) };

public:
	Dog() {
		cout << "디폴트 생성" << endl;
	}
	friend ostream& operator<<(ostream& os, const Dog& dog) {
		return os << "글자 : " << dog.c << ", 숫자 : " << dog.num;
	}
};

int main()
{
	array<Dog, 100> dogs{};
	for (const Dog& dog : dogs)
		cout << dog << endl;

	//문제 : dogs를 binary mode/write로 파일에 기록해라.
	//기록된 파일을 읽어서 num값이 가장 큰 dog를 찾아 화면에 출력

	cout << sizeof dogs << endl;
	cout << typeid(dogs).name() << endl;

	ofstream out{ "dogsData.txt", ios::binary };
	out.write((const char*)dogs.data(), dogs.size() * sizeof(int) * 2);

	ifstream in("dogsData.txt", ios::binary);
	if (not in)
		exit(0);

	array<Dog, 100> indogs{};

	in.read((char*)indogs.data(), dogs.size() * sizeof(int) * 2);

	cout << *max_element(istream_iterator<int>{in}, {});


	//save("STL.cpp");
}