//----------------------------------------------------------
// 2024 STL 4.16 화 (7-2주차)
//  
// 4/23 중간시험
// deque - vector와 list의 중간형태를 띄는 자료구조다.
// ----------------------------------------------------------

#include <iostream>
#include "save.h"
#include "String.h"

#include <vector>
#include <deque>
#include <list>
using namespace std;
extern bool 관찰;

class Test {
	char x[4'096];
};
int main()
{
	// vector<Test> v;//236'2204
	list<Test> v;
	while (true) {
		try{
			v.push_back(Test{});
		}
		catch (...) {
			cout << "끝 : " << v.size() << endl;
			break;
		}
		if (!(v.size() % 10'00000))
			cout << v.size() << " - Still running..." << endl;
	}
	save("STL.cpp");
}