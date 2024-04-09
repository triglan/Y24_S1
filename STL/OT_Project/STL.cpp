//----------------------------------------------------------
// 2024 STL 4.9 ȭ (6-2����)
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
extern bool ����;

int main()
{			
	// [����] Ű���忡�� �Է��� String�� ���̿������� �����Ͽ� ����϶�.
	vector<String> v{ istream_iterator<String>{cin}, {} };//Ű���� �Է� ���ۺ��� �Է� ������ �����϶�.
	
	sort(v.begin(), v.end(), [](const String& a, const String& b) {
		return a.getLen() < b.getLen();
		});

	for ( const String s : v)
		cout << s << " ";
	save("STL.cpp");
}