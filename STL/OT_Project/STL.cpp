//---------------------------------------------------------
// 2024 1�б� STL 5�� 7�� ȭ����
// 
// �ݺ��ڰ� ���� ? : �����͸� �Ϲ�ȭ�� ��.
//---------------------------------------------------------
#include <iostream>
#include "save.h"
#include "string.h"
#include <span>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
extern bool ����;

template<class �ݺ���>
void f(�ݺ��� iter) {
	cout << typeid(iterator_traits<�ݺ���>::iterator_category).name() << endl;
	//C++17
	cout << typeid(�ݺ���::iterator_concept).name() << endl;

}

int main()
{
	String s{ "1357924680" };
	
	sort(s.rbegin(), s.rend());
	
	cout << s << endl;

	save("STL.cpp");
}