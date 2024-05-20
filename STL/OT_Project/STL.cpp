//---------------------------------------------------------
// 2024 1학기 STL 5월 20일 월요일
//
// Associative Container - Set
// 
// set은 어떻게 절렬하는가
// 디폴트 less<Key> -> operator< 를 이용한다.
//---------------------------------------------------------
#include <iostream>
#include "save.h"
#include "string.h"
#include <set>
#include <fstream>
#include <cctype>
#include <algorithm>
using namespace std;
extern bool 관찰;


int main()
{
	//[문제] "이상한 나라의 앨리스.txt" 파일에 있는 단어를 multiset에 읽어 왔다.
	
	multiset<String> s;

	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (!in) return 0;
	
	String str;
	while (in >> str)
		s.insert(str);
	
	cout << "읽은 multiset의 단어 - " << s.size() << endl;

	//[문제] 찾는 단어가 set에 있는지 알려준다.
	while (true) {
		cout << "찾을 단어는? ";
		String word;
		cin >> word;

		auto p = s.find(word);//이렇게 써야 한다. 아까 begin 이런식으로 하면 0점
		//인간의 눈으론 구분하지 못하겠지만 내부에선 엄청나게 빨라졌다.
		
		//+ 이 단어 있어 없어를 출력해주는거 
		bool b = s.contains(word);

		if (b)//가장 빠른 이거 있어? 의 알고리즘
			cout << word << "는 앨리스에 있는 단어 입니다." << endl;
		else
			cout << "그런거 없습니다." << endl;
		
	}

	save("STL.cpp");
}

