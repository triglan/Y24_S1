//---------------------------------------------------------
// 2024 1�б� STL 5�� 6�� ������
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
extern bool ����;

template<class �ݺ���>
void f(�ݺ��� it) {
	//C++17����
	cout << typeid(�ݺ���::iterator_concept).name() << endl;
}

int main()
{
	//[����] ���Ͱ� contiguous���� �Ǻ��Ϸ��� ������ �ٲ�� �Ѵ�.
	//���͸� ���������
	//�ٸ� �����Ϸ��� ���� - SFINAE �̰� ã�ƺ��ñ�ٷ���
	//f(deque<char>::iterator{});
	f(vector<int>{}.begin());
	//f�Լ��� ������ �ٲٸ� contiguous�� iterator�ٶ�� ���Ѵ�.


	save("STL.cpp");
}