//#include <iostream>
//#include "save.h"
//#include "string.h"
//#include <map>
//#include <fstream>
//#include<ranges>
//using namespace std;
//extern bool ����;
//
//
//int main()
//{
//    save("STL.cpp");
//
//    //[����] : "�̻��� ������ �ٸ���.txt" ������ �� �� �о 
//    //�ܾ�� ����Ƚ���� ����϶� //+
//
//    ifstream in{ "�̻��� ������ �ٸ���.txt" };
//    if (not in)return 0;
//
//    //���� �ȵǴ� �ڵ����� ����?
//    //key���� �ܾ�� ���� ���� ���� �������� �ΰ��� ã�� ��ƴ�.
//    map<String, int> Sim;
//    String s;
//    while (in >> s)
//        Sim[s]++;
//
//    //for (const auto& [�ܾ�, ����] : Sim)
//        //cout << �ܾ� << " - " << ���� << endl;
//
//    //[����] ���� ���� �ܾ� ������ ����϶�.
//    //����ver, �ٵ� �̰� 0��¥������? ������ �̷��� ���� 0���̴�.
//    //��ĥ �� ������ multi�� ��� +
//    //�ٵ� multi�� ���� ���� iSm���� �����ڸ� �������� �ʴ´�.
//    //�׷� insert make_pair �Ʒ��� ���� ����Ѵ�.
//    multimap<int, String> iSm;
//    for (const auto& [�ܾ�, ����] : Sim)
//        iSm.insert(make_pair(����, �ܾ�));//++ �̰� ���迡 ���õ�
//
//    cout << "���� ���� �ܾ� ��" << endl;
//    for (const auto& [����, �ܾ�] : iSm | views::reverse)//String�� const auto& �ִµ�
//        cout << �ܾ� << " - " << ���� << endl;
//}