//----------------------------------------------------------
// 2024 STL 4.8 ȭ (6-1����)
//  
// STL - Container
// ǥ�� �����̳ʶ�? - Containers are objects that store other objects.
// ----------------------------------------------------------

#include <iostream>
#include <array>
#include "save.h"
#include "String.h"
using namespace std;

extern bool ����;

int main()
{			
	// [����] a�� "stl.cpp"�� �ִ� �ܾ �����϶�.
	// ���� ������������ �����϶�
	// ȭ�鿡 a�� ����϶�
	array<String, 100>a;

	ifstream in{ "STL.cpp" };
	if (not in)
		return 20240408;

	for (int i = 0; i < 100; ++i)
		in >> a[i];
		

	save("STL.cpp");
}
