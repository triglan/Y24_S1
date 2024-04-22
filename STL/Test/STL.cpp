//-----------------------------------------------------------------------------------
//                                                         (8주 1일)
// list
//-----------------------------------------------------------------------------------
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <fstream>
#include "save.h"
#include "String.h"

extern bool 관찰;

int main()
{
    std::list<String> cont;

    std::ifstream in{ "String.cpp" };
    if (not in)
        return 0;
    cont = { std::istream_iterator<String>{in}, {} };

    관찰 = true;

    // [문제] cont를 길이 오름차순으로 정렬하시오.
    cont.sort([](const String& a, const String& b) {
        return a.getLen() < b.getLen();
        });


    관찰 = false;

    std::cout << std::endl;
    // [문제] 길이가 5인 것들만 화면에 출력하라.
    //준호 코딩, 지난 코드는 save 참조

    save("stl.cpp");
}
