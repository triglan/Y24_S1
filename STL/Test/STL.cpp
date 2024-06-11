#include <iostream>
#include "save.h"
#include "string.h"

using namespace std;
extern bool ����;

template<class InIter, class OutIter>// �ݺ���, �ٸ� �ݺ���

void my_copy(InIter b, InIter e, OutIter d) {
	while (b != e) {
		d = *b;
		++b;
		++d;
	}
}



int main()
{
	save("STL.cpp");

	String s{ "20240514 �⸻���� 6�� 15�� 15�� 2��" };

	my_copy(s.begin(), s.end(), ostream_iterator<char>{cout});
}