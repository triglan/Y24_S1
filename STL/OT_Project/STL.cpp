//----------------------------------------------------------
// 2024 STL 4.15 화 (7-1주차)
//  
// 4/23 중간시험
// ----------------------------------------------------------

#include <iostream>
#include <vector>
#include "save.h"
#include "String.h"
using namespace std;
extern bool 관찰;

int main()
{
	vector<int> v{ 1,2,3,4,5,5,3,4,3,33 };
	
	//[문제] v에서 3을 제거하고 출력하라
	//너무 많이 사용하는 문법이라 이름이 붙어있다
	//erase-remove idiom
	v.erase(remove(v.begin(), v.end(), 3), v.end());//벡터 멤버함수인 삭제 함수

	for (int num : v)
		cout << num << ' ';
	save("STL.cpp");
}