//---------------------------------------------------------
// 2024 1학기 STL 5월 6일 월요일
// 
//---------------------------------------------------------
#include <iostream>
#include "save.h"
#include "string.h"
#include <forward_list>
#include <deque>
#include <vector>
#include <list>

using namespace std;
extern bool 관찰;

template<class 반복자>
void f(반복자 it) {
	//C++17이후
	cout << typeid(반복자::iterator_concept).name() << endl;
}

int main()
{
	//[문제] 벡터가 contiguous인지 판별하려면 질문을 바꿔야 한다.
	//벡터만 컴파일통과
	//다른 컴파일러는 실패 - SFINAE 이걸 찾아보시길바래요
	//f(deque<char>::iterator{});
	f(vector<int>{}.begin());
	//f함수를 저렇게 바꾸면 contiguous한 iterator다라고 답한다.


	save("STL.cpp");
}