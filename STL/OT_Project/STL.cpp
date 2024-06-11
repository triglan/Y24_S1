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
extern bool 관찰;
default_random_engine dre;
int main() {
    save("STL.cpp");
    vector<int> v(100);
    ranges::iota(v, 1); //constrained-algorithm (컨셉으로 인자에 제약을 가한 함수)
    ranges::shuffle(v, dre);
    ranges::sort(v.begin(), v.begin() + 20);
    for (int num : views::filter(v, [](int n) { return n & 1; })) //[begin, predicate)
        print("{:4}", num);
}