#include <iostream>
#include "save.h"
#include "String.h"
#include <array>
#include <vector>
#include <list>
#include <print>
#include <random>
#include <algorithm>
#include <numeric>
#include <ranges>
using namespace std;
extern bool ����;
default_random_engine dre;
int main() {
    save("STL.cpp");
    vector<int> v(100);
    ranges::iota(v, 1); //constrained-algorithm (�������� ���ڿ� ������ ���� �Լ�)
    ranges::shuffle(v, dre);
    ranges::sort(v.begin(), v.begin() + 20);
    for (int num : views::filter(v, [](int n) { return n & 1; })) //[begin, predicate)
        print("{:4}", num);
}