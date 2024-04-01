//----------------------------------------------------------
// 2024 STL 4.1 ȭ (5-1����)
//  
// callable type - ������ Ÿ���� �ִ�.
// ȣ�� ������ Ÿ���� ��ǥ�ϴ� Ÿ���� ������� - function
// 
// sort�� �� � �������� ���������� ��� sort �Լ����� �˷��ֳ�?
// 1. �Լ������͸� ���⳪��
// 2. ���ٸ� �����Ѵ� -> visual studio������ �Լ� ��ü ��� �ܾ� ����
// 3. () ������(FUNCTION CALL)�� �����ε��� Ŭ������ ��ü -> �Լ� ��ü
// 
// ----------------------------------------------------------

#include <iostream>
#include <string>
#include <memory>
#include "save.h"
using namespace std;

class String {
	size_t len{};
	unique_ptr<char[]> p;

public:
	String(const char* s) : len(strlen(s)) {
		p = make_unique<char[]>(len);
		memcpy(p.get(), s, len);
	}
	friend ostream& operator<<(ostream& os, const String& s) {
		for (size_t i = 0; i < s.len; ++i)
			os << s.p.get()[i];
		return os;
	}
};
int main()
{
	String s{ "STL�� �����ϱ� ���� Ŭ�����Դϴ�." };
	//String t = s; -> ���ư� �� �ְ� �ڵ�

	cout << s << endl;
	//cout << t << endl;

	save("STL.cpp");
}
