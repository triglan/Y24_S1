#include <iostream>
#include "save.h"
#include "String.h"
#include <list>
#include <fstream>
#include <vector>
#include <deque>
using namespace std;
extern bool 관찰;

class Test {
	char x[4'096];
};
int main()
{
	//list : 500, deque : 500, vector : 2000
	deque<String> cont;
	cout << "리스트의 크기 - " << sizeof cont << endl;//리스트의 크기 - 16
	관찰 = true;
	//[문제] "string.cpp"에 있는 단어를 cont에 저장하라

	ifstream in{ "String.cpp" };
	if (not in) return 0;
	String s;
	while (in >> s) {
		cont.emplace_back(s);//이건 어떨까 복사생성이 안나올까? -> 절대 안되지 그저 복사생성될 뿐이야.
		//s 객체가 그냥 객체니까.
	}

	관찰 = false;
	cout << endl;
	for (const String& s : cont)
		cout << s << endl;
	save("STL.cpp");
}