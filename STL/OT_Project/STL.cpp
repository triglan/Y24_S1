//---------------------------------------------------------
// 2024 1학기 STL 5월 27일 월요일
//
// Unordered associative container
// - unordered의 의미
// - 메모리 구조는 어떻게?
// - 내가 만든 String도 관리가능해?
// 
// 6월 11일 화요일(15주 2) - 기말시험
//---------------------------------------------------------
#include <iostream>
#include "save.h"
#include "string.h"
#include <unordered_set>

using namespace std;
extern bool 관찰;

int main()
{
	unordered_set<int> us{ 3, 1, 4, 2 };

	us.insert(7);//데이터를 중가에 삽입하면..? 3 1 4 2 7 엥 뒤에 붙었네 순서 있네 뭘
	us.insert(10);//3 1 4 10 2 7 엥 이번엔 이렇게 뜨네


	for (int num : us)
		cout << num << ' ';
	cout << endl;


	save("STL.cpp");
}

