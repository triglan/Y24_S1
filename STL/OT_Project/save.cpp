//----------------------------------------------------------
// 2024 STL 3.5 월 9-10시								(1-1)
//
// Visual Studio 17.9.0 이상, Release/x64
// Project 속성/std:c++ latest <== 미리보기 최신, SDL 검사 - NO 끄기
// 
// 한학기 강의를 저장하는 save 만들기
// 내일 파일 분리
// ----------------------------------------------------------

#include <iostream>
#include "save.h"
using namespace std;

void save(string_view); // 언제나 배열은 포인터로 변한다? const char[] 이런식으로 쓰지마라. string으로

int main()
{
	std::cout << "STL 입니다." << '\n';

	std::cout << sizeof(string) << endl;

	save("STL.cpp");
}

void save(string_view fileName) {
	// fileName을 읽을 파일로 연다.
	//ifstream in;
	//cout << sizeof in << endl; // 너 몇바이트 짜리야? ifstream은 272바이트 만큼 차지하네
	//cout << addressof( in ) << endl; // 넌 어디에 살고 있니?, 얘는 괄호에 넣어야 하네.
	//cout << typeid( in ).name() << endl; // 네 자료형은 뭐임?

	ifstream in{ fileName.data() }; // 파일 포인터를 유지하게된다. data로 읽기모드로 파일을 열었다.
	if (not in) { // !보단 not 초보자용 코드가 더 읽기 쉽다.
		cout << fileName << " - 파일 열기 실패" << endl;
		exit(0);
	}

	// 저장할 파일을 덧붙여 쓰기 모드로 연다.
	ofstream out{ "2024 1학기 STL 월910화78 강의저장.txt", ios::app };
	// output은 존재하지 않으면 새로 만들어서 상관 x
	// input은 체크를 해야한다.


	// 읽을 파일의 내용을 모두 읽어 쓸 파일에 덧붙여 쓴다.
	// SLT 자료구조와 알고리즘을 이용해본다.

	// 저장한 시간기록
	out << endl << endl << endl;

	auto now = chrono::system_clock::now();				// epoch로 부터 증가한 tick
	auto time = chrono::system_clock::to_time_t(now);	// UTC 시간으로 변환
	auto lt = localtime(&time);//포인터를 인자로 넘겨주면 컴파일러가 위험하다 한다. 현지시간으로 변환

	auto old = out.imbue(locale("ko_KR")); // 출력파일의 지역을 한국으로 바꾼다.
	// 날짜를 내 마음대로 출력한다.
	out << "==============================================" << endl;
	out << fileName << put_time(lt, ", 저장시간: %x %A %X ") << endl;
	out << "==============================================" << endl;
	out.imbue(old); // 원상복구 윈플때 브러시 쓰고 다시 원상복구 시키는 그런 것. 전세 살다가 나갈떄 언상복구 해야지

	// 좋은 코딩은 아니다 저장을 위한 것.
	//벡터 v에 코드의 모든 내용이 저장되어 있다.
	vector<char> v{ istreambuf_iterator<char>{in}, {} };//초기화를 해볼 것이다.

	//for (char c : v)
	//	out << c; <- 이게더 좋은 코드라고 한다. 저장하는 코드인듯.

	copy(v.begin(), v.end(), ostreambuf_iterator<char>{out}); // 알고리즘을 활용해 더 안좋은 코드지만 저장해봄
	// 벡터의 시작부터 끝까지 out파일로 저장한다.
	// 실행할 때마다 덧붙여서 저장된다.

}