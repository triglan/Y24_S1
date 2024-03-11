//----------------------------------------------------------
// 2024 STL 3.5 월 9-10시		(1-1)
// ----------------------------------------------------------

#include <iostream>
#include "save.h"

#include <string_view>
#include <fstream>
#include <algorithm>
using namespace std;

	
int main()
{
	//문제 : 파일 int값들.txt에는 몇개인지 모르는 int가 저장되어 있다.
	//모두 몇개인지 출력하고 그 중에 가장 큰 값도 화면에 출력하시오

	ifstream in{ "int값들.txt" };
	if (not in)
		exit(0);
	
	cout << *max_element(istream_iterator<int>{in}, {});
	

	save("STL.cpp");
}
