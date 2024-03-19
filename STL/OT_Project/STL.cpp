//----------------------------------------------------------
// 2024 STL 3.5 월 9-10시
// 24-03-18 
// 실행 파일의 메모리 영역 - STACK CODE DATA Free store(Heap)
// ----------------------------------------------------------

#include <iostream>
#include "save.h"
using namespace std;

// [문제] 프로그램에서 이용할 수 있는 전역변수의 최대 크기는?
//int 최대값을 써봐라

int num[1'0000'0000] = { 1,2,3 };//1억개

int main()
{ 
	num[9999'9999] = 1234567890;
	cout << num[9999'9999] << endl;

	cout << "키를 누르면 프로그램이 끝남" << endl;
	char c;
	cin >> c;
	save("STL.cpp");
}