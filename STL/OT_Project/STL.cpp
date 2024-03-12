//----------------------------------------------------------
// 2024 STL 3.5 월 9-10시		(1-1)
// ----------------------------------------------------------

#include <iostream>
#include "save.h"
#include <array>
#include <print>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;

	
int main()
{
	//문제 : int 100개를 저장하는데 메모리 bit값을 그대로 저장하자.
	//int 100개 = sizeof(int) * 100 = 400 bytes

	array<int, 100>a{};

	iota(a.begin(), a.end(), 1);

	ofstream out{ "int100개를메모리그대로저장.txt", ios::binary };
	//로우레벨 i/o를 사용한다.
	out.write( (const char*)(a.data()), a.size() * sizeof(int)); // 얘보다 빠른 코드는 없다. io 장치끼리 데이터를 교환함.

	//401바이트가 나오네 왜? OS가 중간에 개입했기 때문이야
	//ofstream out에서 txt파일로 연 순간 저수준 io를 사용한순간 바이트를 변환하면서
	//바이트가 늘어난다. ios::binary로 바이트 변환 안한다고 알려주면 400바이트 그대로 나온다
	

	save("STL.cpp");
}
