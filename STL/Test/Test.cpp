#include <iostream>
#include "save.h"
#include "string.h"

#include <algorithm>
#include <vector>

template <class �ݺ���, class ��>
�ݺ��� my_find(�ݺ��� b, �ݺ��� e, �� val) {
    while (b != e) {//�˻��� �����Ͱ� �ִ� ����, end�� �������� �ʾҴٸ�
        if (*b == val)
            return b;
        ++b;
    }
}