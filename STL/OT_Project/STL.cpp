//----------------------------------------------------------
// 2024 STL 3.5 �� 9-10��		(1-1)
// ----------------------------------------------------------

#include <iostream>
#include "save.h"

#include <string_view>
#include <fstream>
#include <algorithm>
using namespace std;

	
int main()
{
	//���� : ���� int����.txt���� ����� �𸣴� int�� ����Ǿ� �ִ�.
	//��� ����� ����ϰ� �� �߿� ���� ū ���� ȭ�鿡 ����Ͻÿ�

	ifstream in{ "int����.txt" };
	if (not in)
		exit(0);
	
	cout << *max_element(istream_iterator<int>{in}, {});
	

	save("STL.cpp");
}
