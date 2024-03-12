//----------------------------------------------------------
// 2024 STL 3.5 월 9-10시		(1-1)
// ----------------------------------------------------------

#include <iostream>
#include "save.h"
#include <fstream>
#include <array>



using namespace std;

// 문제 : "int100개를메모리그대로저장.txt"에
// int값 100개가 write 함수를 사용하여 기록되어 있다.
// 파일은 binary 모드로 열어 기록되었다. 
// 파일에 기록된 int값 100개를 메모리로 읽어온 후
// 화면에 그 값을 출력하라.

int main()
{
	ifstream in("int100개를메모리그대로저장.txt", ios::binary );
	if (not in)
		exit(0);

	array<int, 100>a;

	in.read((char*)a.data(), 400);

	for (int num : a)
		cout << num << "\t";
	cout << endl;

	save("STL.cpp");
}
