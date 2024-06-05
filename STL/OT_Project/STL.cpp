//---------------------------------------------------------
// 2024 1학기 STL 6월 3일 화요일
//
// 6/11 화요일 - 기말시험
// 
// C++20 Concept / Range
//---------------------------------------------------------
#include <iostream>
#include "save.h"
#include "string.h"
#include <algorithm>
#include <list>
#include <ranges>

using namespace std;
extern bool 관찰;

template<class T>
//정수 or 부동소수점수
concept 숫자만 = is_integral_v<T> or is_floating_point_v<T>;

template<숫자만 T>
T add(T a, T b) {
    return a + b;
}

int main()
{
    list<int> list{ 1,2,3 };

    ranges::sort(list.begin(), list.end(),);

    save("STL.cpp");
}