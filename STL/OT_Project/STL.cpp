//---------------------------------------------------------
// 2024 1�б� STL 5�� 13�� ȭ����
// 
// �˰��� �Լ��� �ݺ��ڸ� ���ڷ� �޴´�.
//---------------------------------------------------------
#include <iostream>
#include "save.h"
#include "string.h"

#include <algorithm>
#include <vector>

template <class �ݺ���, class ��>
�ݺ��� my_find(�ݺ��� b, �ݺ��� e, �� val) {
	//���� �ڵ��Ѵ�.
}

using namespace std;
extern bool ����;


int main()
{
	save("STL.cpp");

	String s{ "20240513 - stl, container iterator algorithm" };

	//[����] ����ڰ� ã�� ���ڰ� s�� �ִ��� �˷�����.

	while (true) {
		cout << "ã�� ���ڴ�? ";
		char ch;
		cin >> ch;

		auto p = my_find(s.begin(), s.end(), ch);
		if (p != s.end())
			cout << "��ġ - " << "�� ã��" << endl;
		else
			cout << ch << "�� s�� ���� �����Դϴ�." << endl;
	}

}