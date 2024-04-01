//----------------------------------------------------------
// 2024 STL 4.1 화 (5-1주차)
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
#include <string>
#include <memory>
#include "save.h"
using namespace std;

class String {
	size_t len{};
	unique_ptr<char[]> p;

public:
	String(const char* s) : len(strlen(s)) {
		p = make_unique<char[]>(len);
		memcpy(p.get(), s, len);
	}
	friend ostream& operator<<(ostream& os, const String& s) {
		for (size_t i = 0; i < s.len; ++i)
			os << s.p.get()[i];
		return os;
	}
};
int main()
{
	String s{ "STL을 관찰하기 위한 클래스입니다." };
	//String t = s; -> 돌아갈 수 있게 코딩

	cout << s << endl;
	//cout << t << endl;

	save("STL.cpp");
}
