//-------------------------------------------------------------------
// save.cpp
// 한 학기 강의를 저장할 함수
//-------------------------------------------------------------------
#include <string_view>
#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "save.h"
void save(std::string_view fileName)
{
    // fileName을 읽을 파일로 연다.
    std::ifstream in{ fileName.data() };
    if (not in) {
        std::cout << fileName << " - 파일 열기 실패" << std::endl;
        exit(0);
    }

    // 저장할 파일을 덧붙여 쓰기 모드로 연다.
    std::ofstream out{ "0430_9-1_강의저장.txt", std::ios::app };

    // 저장한 시간을 기록한다.
    out << std::endl << std::endl << std::endl;
    auto now = std::chrono::system_clock::now();               // epoch(찾아보셈)
    auto time = std::chrono::system_clock::to_time_t(now);         // UTC 시간으로 변환
    auto lt = localtime(&time);   // 현지시간으로 변환(컴퓨터 시간 따라감)

    auto old = out.imbue(std::locale("ko_KR"));
    // 날짜를 내 마음대로 출력한다.
    out << "================================================" << std::endl;
    out << fileName << std::put_time(lt, ", 저장시간: %x %A %X") << std::endl;
    out << "================================================" << std::endl;
    out.imbue(old);


    // 읽을 파일의 내용을 모두 읽어 쓸 파일에 덧붙여 쓴다.
    // STL 자료구조와 알고리즘을 이용해 본다. (좋은 코딩은 아님, 예를 들어서 보여줄 뿐...)
    std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };
    copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{out});
}