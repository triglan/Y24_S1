#include <iostream>
#include "save.h"
#include "String.h"
#include <list>
#include <fstream>
#include <vector>
#include <deque>
using namespace std;
extern bool ����;

class Test {
	char x[4'096];
};
int main()
{
	//list : 500, deque : 500, vector : 2000
	deque<String> cont;
	cout << "����Ʈ�� ũ�� - " << sizeof cont << endl;//����Ʈ�� ũ�� - 16
	���� = true;
	//[����] "string.cpp"�� �ִ� �ܾ cont�� �����϶�

	ifstream in{ "String.cpp" };
	if (not in) return 0;
	String s;
	while (in >> s) {
		cont.emplace_back(s);//�̰� ��� ��������� �ȳ��ñ�? -> ���� �ȵ��� ���� ��������� ���̾�.
		//s ��ü�� �׳� ��ü�ϱ�.
	}

	���� = false;
	cout << endl;
	for (const String& s : cont)
		cout << s << endl;
	save("STL.cpp");
}