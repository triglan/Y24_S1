//---------------------------------------------------------
// 2024 1학기 STL 5월 21일 화요일
//
// Associative Container - map<key, value> -> dictionary
// 
// 독특한 기능 : map -> 연관 배열처럼 사용할 수 있다.
// 
// 
// 6월 11일 화요일(15주 2) - 기말시험
//---------------------------------------------------------
#include <iostream>
#include "save.h"
#include "string.h"
#include <map>
#include <fstream>
#include <list>
using namespace std;
extern bool 관찰;


int main()
{
	//그룹과 멤버
	map<String, list<String>>m{ {"아이브", {"안유진", "가을", "레이", "장원영", "리즈", "이서"}}};
	m.insert(pair<String, list<String>> {"블랙핑크", {"지수", "제니", "로제", "리사"}});
	m.insert(make_pair("아이유", list<String>{ "아이유" }));
	m["르세라핌"] = { "사쿠라","김채원","허윤진","허윤진","카즈하","홍은채"};

	//전체 출력
	for (const auto& [그룹, 멤버들] : m) {
		cout << 그룹 << " - " << 멤버들.size() << "명, ";
		for (const auto& 멤버 : 멤버들)
			cout << 멤버 << " ";
		cout << endl;
	}
	save("STL.cpp");
}

