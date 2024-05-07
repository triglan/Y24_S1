//---------------------------------------------------------
// 2024 1학기 STL 5월 7일 화요일
// 
// 반복자가 뭐야 ? : 포인터를 일반화한 것.
//---------------------------------------------------------
#include <iostream>
#include "save.h"
#include "string.h"
#include <span>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
extern bool 관찰;

template<class 반복자>
void f(반복자 iter) {
	cout << typeid(iterator_traits<반복자>::iterator_category).name() << endl;
	//C++17
	cout << typeid(반복자::iterator_concept).name() << endl;

}

int main()
{
	String s{ "1357924680" };
	
	sort(s.rbegin(), s.rend());
	
	cout << s << endl;

	save("STL.cpp");
}