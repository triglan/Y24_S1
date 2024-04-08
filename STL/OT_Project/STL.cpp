//----------------------------------------------------------
// 2024 STL 4.8 화 (6-1주차)
//  
// STL - Container
// 표준 컨테이너란? - Containers are objects that store other objects.
// ----------------------------------------------------------

#include <iostream>
#include <array>
#include "save.h"
#include "String.h"
using namespace std;

extern bool 관찰;

int main()
{			
	// [문제] a에 "stl.cpp"에 있는 단어를 저장하라.
	// 길이 오름차순으로 정렬하라
	// 화면에 a를 출력하라
	array<String, 100>a;

	ifstream in{ "STL.cpp" };
	if (not in)
		return 20240408;

	for (int i = 0; i < 100; ++i)
		in >> a[i];
		

	save("STL.cpp");
}
