#include <iostream>
#include "save.h"
#include "string.h"

using namespace std;
extern bool 관찰;

template<class InIter, class OutIter>// 반복자, 다른 반복자

void my_copy(InIter b, InIter e, OutIter d) {
	while (b != e) {
		d = *b;
		++b;
		++d;
	}
}



int main()
{
	save("STL.cpp");

	String s{ "20240514 기말시험 6월 15일 15주 2일" };

	my_copy(s.begin(), s.end(), ostream_iterator<char>{cout});
}