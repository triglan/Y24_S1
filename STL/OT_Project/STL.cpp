//----------------------------------------------------------
// 2024 STL 3.25 �� (4-1����)
//  
// �޸� �����Ҵ� - RAII - �޸�, ����, jthread 
// 
// ������ C++ ���� ������� �ʾƾ� �� �͵�
// char* -> string
// T[N] -> array
// T* -> unique_ptr, shared_ptr(����Ʈ �����ͷ� ��ü)
// ----------------------------------------------------------

#include <iostream>
#include "save.h"
using namespace std;

class Dog {
public:
	Dog() { cout << "�� ����" << endl; }
	~Dog() { cout << "�� �Ҹ�" << endl; }

};
class Smart_ptr {
	Dog* p;
public:
	Smart_ptr(Dog* p) : p{ p } {}
	~Smart_ptr() { delete p; }
};
void f() {
	cout << "f �Լ� ����" << endl;

	{
		Smart_ptr p(new Dog);	//stack - unwinding ������ �Ųٷ� �ǰ����� �����Ѵ�.
		throw 1234;
	}

	cout << "f ��" << endl;
}

int main()
{
	cout << "���� ����" << endl;

	try {// ������ �߻��� �� �ִ� ���� ���� �־���� �Ѵ�
		f();//�ڿ��� Ȯ���ϰ� �����ϴ� �Լ�	
	}
	catch (...) {//���ܸ� ĳġ�ϰ� �Ǹ�..

	}
	save("STL.cpp");

	cout << "���� ��" << endl;
}