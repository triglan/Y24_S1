//----------------------------------------------------------
// 2024 STL 3.25 월 (4-1주차)
//  
// 메모리 동적할당 - RAII - 메모리, 파일, jthread 
// 
// 앞으로 C++ 언어에서 사용하지 않아야 할 것들
// char* -> string
// T[N] -> array
// T* -> unique_ptr, shared_ptr(스마트 포인터로 대체)
// ----------------------------------------------------------

#include <iostream>
#include "save.h"
using namespace std;

class Dog {
public:
	Dog() { cout << "개 생성" << endl; }
	~Dog() { cout << "개 소멸" << endl; }

};
class Smart_ptr {
	Dog* p;
public:
	Smart_ptr(Dog* p) : p{ p } {}
	~Smart_ptr() { delete p; }
};
void f() {
	cout << "f 함수 시작" << endl;

	{
		Smart_ptr p(new Dog);	//stack - unwinding 스택이 거꾸로 되감김을 보장한다.
		throw 1234;
	}

	cout << "f 끝" << endl;
}

int main()
{
	cout << "메인 시작" << endl;

	try {// 문제가 발생할 수 있는 곳에 전부 넣어줘야 한다
		f();//자원을 확보하고 정리하는 함수	
	}
	catch (...) {//예외를 캐치하게 되면..

	}
	save("STL.cpp");

	cout << "메인 끝" << endl;
}