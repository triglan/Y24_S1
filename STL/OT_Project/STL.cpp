//----------------------------------------------------------
// 2024 STL 4.9 화 (6-2주차)
//  
// vector - dynamic array
// ----------------------------------------------------------

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "save.h"
#include "String.h"
using namespace std;
extern bool 관찰;

int main()
{			
	// [문제] 키보드에서 입력한 String을 길이오름차순 정렬하여 출력하라.
	vector<String> v{ istream_iterator<String>{cin}, {} };//키보드 입력 시작부터 입력 끝까지 저장하라.
	
	sort(v.begin(), v.end(), [](const String& a, const String& b) {
		return a.getLen() < b.getLen();
		});

	for ( const String s : v)
		cout << s << " ";
	save("STL.cpp");
}