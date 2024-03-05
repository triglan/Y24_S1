//----------------------------------------------------------
// 2024 STL 3.5 월 9-10시								(1-1)
//
// Visual Studio 17.9.0 이상, Release/x64
// Project 속성/std:c++ latest <== 미리보기 최신, SDL 검사 - NO 끄기
// 
// 한학기 강의를 저장하는 save 만들기
// ----------------------------------------------------------

#include <random>
#include <format>
#include <iostream>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 1000, 9999 };

// 문제 가장 큰 수를 찾아 화면에 출력하라
int main()
{
	int a[1000];
	
	for (int& num : a)
		num = uid(dre);

	for (int num : a)
		cout << format("{:8}", num);

	// 가장 큰 수를 찾는 프로그램
	int big{ numeric_limits<int>::min()}; // int가 가질 수 있는 가장 최소의 값.
	for (int num : a) {
		if (big < num) {
			big = num;
		}
	}

	cout << endl << endl << "가장 큰 수 : " << big << endl;
	save("STL.cpp");
}
