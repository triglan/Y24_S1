#include <iostream>
#include "save.h"
#include "string.h"

#include <algorithm>
#include <vector>

template <class 반복자, class 값>
반복자 my_find(반복자 b, 반복자 e, 값 val) {
    while (b != e) {//검색할 데이터가 있는 동안, end에 도달하지 않았다면
        if (*b == val)
            return b;
        ++b;
    }
}