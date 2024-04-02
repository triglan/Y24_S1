//----------------------------------------------------------
// 2024 STL 4.2 화 (5-2주차)
//  
// callable type - 무한한 타입이 있다.
// 호출 가능한 타입을 대표하는 타입을 만들었따 - function
//	
// sort할 때 어떤 기준으로 정렬할지를 어떻게 sort 함수에게 알려주나?
// 1. 함수포인터를 전닳나다
// 2. 람다를 전달한다 -> visual studio에서는 함수 객체 라고 단언 가능
// 3. () 연산자(FUNCTION CALL)를 오버로딩한 클래스의 객체 -> 함수 객체
// 
// ----------------------------------------------------------

#include <iostream>
#include <array>
#include "save.h"
#include "String.h"
#include <algorithm>
using namespace std;

extern bool 관찰;

int main()
{			
	array<String, 5> a{ "aersbc", "cdef", "efghght", "rdsfsagaa", "tokbsdfsrlk"};
	//[문제] sort를 사용하여 a가 관리하는 string을 오름차순으로 정렬한 후 출력하라
	//관찰 = true;
	for (const String& s : a)
		sort(s.getMem(), s.getMem() + s.getLen());
	관찰 = false;

	cout << "길이 오름차순 정렬결과" << endl;
	for (const String& s : a) ///&의 의미는 복사하지 마라는 뜻
		cout << s << endl;
	save("STL.cpp");
}
