//----------------------------------------------------------
// 2024 STL 4.16 ȭ (7-2����)
//  
// 4/23 �߰�����
// deque - vector�� list�� �߰����¸� ��� �ڷᱸ����.
// ----------------------------------------------------------

#include <iostream>
#include "save.h"
#include "String.h"

#include <vector>
#include <deque>
#include <list>
using namespace std;
extern bool ����;

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
			cout << "�� : " << v.size() << endl;
			break;
		}
		if (!(v.size() % 10'00000))
			cout << v.size() << " - Still running..." << endl;
	}
	save("STL.cpp");
}