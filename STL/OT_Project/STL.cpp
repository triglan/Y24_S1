//---------------------------------------------------------
// 2024 1�б� STL 5�� 20�� ������
//
// Associative Container - Set
// 
// set�� ��� �����ϴ°�
// ����Ʈ less<Key> -> operator< �� �̿��Ѵ�.
//---------------------------------------------------------
#include <iostream>
#include "save.h"
#include "string.h"
#include <set>
#include <fstream>
#include <cctype>
#include <algorithm>
using namespace std;
extern bool ����;


int main()
{
	//[����] "�̻��� ������ �ٸ���.txt" ���Ͽ� �ִ� �ܾ multiset�� �о� �Դ�.
	
	multiset<String> s;

	ifstream in{ "�̻��� ������ �ٸ���.txt" };
	if (!in) return 0;
	
	String str;
	while (in >> str)
		s.insert(str);
	
	cout << "���� multiset�� �ܾ� - " << s.size() << endl;

	//[����] ã�� �ܾ set�� �ִ��� �˷��ش�.
	while (true) {
		cout << "ã�� �ܾ��? ";
		String word;
		cin >> word;

		auto p = s.find(word);//�̷��� ��� �Ѵ�. �Ʊ� begin �̷������� �ϸ� 0��
		//�ΰ��� ������ �������� ���ϰ����� ���ο��� ��û���� ��������.
		
		//+ �� �ܾ� �־� ��� ������ִ°� 
		bool b = s.contains(word);

		if (b)//���� ���� �̰� �־�? �� �˰���
			cout << word << "�� �ٸ����� �ִ� �ܾ� �Դϴ�." << endl;
		else
			cout << "�׷��� �����ϴ�." << endl;
		
	}

	save("STL.cpp");
}

