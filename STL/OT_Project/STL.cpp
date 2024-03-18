//----------------------------------------------------------
// 2024 STL 3.5 월 9-10시
// 24-03-18 
// 실행 파일의 메모리 영역 - STACK CODE DATA Free store(Heap)
// ----------------------------------------------------------

#include <iostream>
#include "save.h"
#include <fstream>
#include <algorithm>
#include <array>
using namespace std;

//[문제] eclass에 가면 개들 파일이 있다. 파일을 binary모드로 기록했다.
//여기에는 class Dog 객체 100개 가록되어 있다. write함수를 사용하여 기록하였다.
//class Dog의 멤버는 다음과 같다.
//파일을 읽어 num값이 가장 큰 dog객체를 화면에 출력하라
//[변형] -->	여기에는 몇 개 인지 모르는 class Dog 객체를 write했다.
//[2] class Dog 객체 100개 기록되어 있다.
//[3] 1000미만인 Dog 객체의 수를 출력해라.

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
	//바이너리로 열지 않았는데도 정상적으로 종료되면서 정상적인 것처럼 보이기에 조심해야 된다
	//이 파일은 어떻게 기록되어 있는지 binary 기억해라.
	ifstream in{ "개들", ios::binary};
	if (not in) {
		cout << "파일을 열 수 없다" << endl;
		return 0;
	}
	array<Dog, 100> dogs;
	in.read((char*)&dogs, sizeof(Dog) * 100);
		
	//1000미만의 dog를 출력하기 위해 count 사용
	int cnt = count_if(dogs.begin(), dogs.end(), [](const Dog& dog) {
		return dog.getNum() % 2; // 홀수 일 때 참, 짝수 일 때 거짓
		});
	cout << "값이 1000 미만인 Dog의 개수 - " << cnt << endl;
	save("STL.cpp");
}