//---------------------------------------------------------
// 2024 1학기 STL 5월 14일 화요일
//
// Associative 
//---------------------------------------------------------
#include <iostream>
#include "save.h"
#include "string.h"
#include <vector>
using namespace std;
extern bool 관찰;

template<class InIter, class OutIter>// 반복자, 다른 반복자

void my_copy(InIter b, InIter e, OutIter d) {
	while (b != e) {
		*d = *b;//d는 cout인데 출력할 위치를 한칸씩 밀기 위해서 d도 ++하고 있다.
		//실제로는 *d.operator=(*b){
		//	v.push_back(*b); } 이런 활동이 이뤄지고 있다. 설명 코드, 실제로 돌아가는 코드는 아님.
		++b;
		++d;
	}
}



int main()
{
	save("STL.cpp");

	String s{ "20240514 기말시험 6월 15일 15주 2일" };
	vector<char> v;
	v.reserve(100);//벡터에 자리 100칸을 준다. 자리를 안주니까 터졌었다.
	my_copy(s.begin(), s.end(), back_inserter(v));//back_inserter로 넣으니까 실행이 된다. 
	for (char c : v) {
		cout << c;
	}
	//벡터에 데이터는 100% 들어갔는데 왜 출력을 못해? 
	//데이터는 들어갔는데 벡터가 데이터가 들어간걸 모르니까 begin과 end가 가리키는 위치가 같다.
	//그래서 아무 것도 출력하지 못하고 있는 거다.
	//벡터가 우리에게 알려준게 아니라 우리가 무식하게 벡터 위치에다가 넣은거니까
	//벡터는 사이즈 관리와 원소관리를 따로 한다
}

