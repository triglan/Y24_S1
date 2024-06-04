//---------------------------------------------------------
// 2024 1�б� STL 6�� 3�� ȭ����
//
// 6/11 ȭ���� - �⸻����
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
extern bool ����;

template<class T>
//���� or �ε��Ҽ�����
concept ���ڸ� = is_integral_v<T> or is_floating_point_v<T>;

template<���ڸ� T>
T add(T a, T b) {
    return a + b;
}

int main()
{
    list<int> list{ 1,2,3 };

    ranges::sort(list.begin(), list.end(),);

    save("STL.cpp");
}