//-----------------------------------------------------------------------------------
//                                                         (8�� 1��)
// list
//-----------------------------------------------------------------------------------
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <fstream>
#include "save.h"
#include "String.h"

extern bool ����;

int main()
{
    std::list<String> cont;

    std::ifstream in{ "String.cpp" };
    if (not in)
        return 0;
    cont = { std::istream_iterator<String>{in}, {} };

    ���� = true;

    // [����] cont�� ���� ������������ �����Ͻÿ�.
    cont.sort([](const String& a, const String& b) {
        return a.getLen() < b.getLen();
        });


    ���� = false;

    std::cout << std::endl;
    // [����] ���̰� 5�� �͵鸸 ȭ�鿡 ����϶�.
    //��ȣ �ڵ�, ���� �ڵ�� save ����

    save("stl.cpp");
}
