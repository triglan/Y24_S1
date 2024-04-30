//-------------------------------------------------------------------
// save.cpp
// �� �б� ���Ǹ� ������ �Լ�
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
    // fileName�� ���� ���Ϸ� ����.
    std::ifstream in{ fileName.data() };
    if (not in) {
        std::cout << fileName << " - ���� ���� ����" << std::endl;
        exit(0);
    }

    // ������ ������ ���ٿ� ���� ���� ����.
    std::ofstream out{ "0430_9-1_��������.txt", std::ios::app };

    // ������ �ð��� ����Ѵ�.
    out << std::endl << std::endl << std::endl;
    auto now = std::chrono::system_clock::now();               // epoch(ã�ƺ���)
    auto time = std::chrono::system_clock::to_time_t(now);         // UTC �ð����� ��ȯ
    auto lt = localtime(&time);   // �����ð����� ��ȯ(��ǻ�� �ð� ����)

    auto old = out.imbue(std::locale("ko_KR"));
    // ��¥�� �� ������� ����Ѵ�.
    out << "================================================" << std::endl;
    out << fileName << std::put_time(lt, ", ����ð�: %x %A %X") << std::endl;
    out << "================================================" << std::endl;
    out.imbue(old);


    // ���� ������ ������ ��� �о� �� ���Ͽ� ���ٿ� ����.
    // STL �ڷᱸ���� �˰����� �̿��� ����. (���� �ڵ��� �ƴ�, ���� �� ������ ��...)
    std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };
    copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{out});
}