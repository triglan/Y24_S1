#include <iostream>
#include "save.h"
#include "string.h"
#include <map>
#include <fstream>
using namespace std;
extern bool ����;


int main()
{
    //[����] : "�̻��� ������ �ٸ���.txt" ������ �� �� �о 
    //�ҹ��ڿ� ���� Ƚ���� ������ ���� ����϶�. �빮�ڴ� ��� �ҹ��ڷ�.
    //a - 333��, b - 454��... z - 52��

    ifstream in{ "�̻��� ������ �ٸ���.txt" };
    if (not in)return 0;

    map<char, int> m;
    char c;
    while (in >> c) {//���� ���� �����ϱ� ���� �̿��ؼ�
        if (isalpha(c))
            m[tolower(c)]++;	//c�� key������ �ִ´�. �ش� �ҹ��� key���� ��� ++����
    }
    for (auto [�ҹ���, ����] : m) // ����ȭ�� binding
        cout << �ҹ��� << " - " << ���� << endl;

    // [����] ���� ������������ ����϶�.
    // 1. ���Ϳ��ٰ� �Űܼ� sort�ϴ� ����� �ִ�.
    // 2. �����ϴ°� ������ key������ map�� �ϳ� ����� ����
    map<int, char> icm;//less<int>�� ����Ʈ�� �����ֱ� ������ ������������ ���ĵǰ� �־���.
    //greater�̶�� �ϸ� ������������ ���ĵ� ���̴�.
    for (auto [�ҹ���, ����] : m)
        icm[����] = �ҹ���;

    cout << "���� �������� ������ ���" << endl;

    //+ �̹��� ���������� ����Ѵ�.
    for (auto p = icm.rbegin(); p != icm.rend(); ++p)
        cout << p->second << " - " << p->first << endl;//


}