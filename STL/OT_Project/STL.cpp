//---------------------------------------------------------
// 2024 1�б� STL 5�� 14�� ȭ����
//
// Associative 
//---------------------------------------------------------
#include <iostream>
#include "save.h"
#include "string.h"
#include <vector>
using namespace std;
extern bool ����;

template<class InIter, class OutIter>// �ݺ���, �ٸ� �ݺ���

void my_copy(InIter b, InIter e, OutIter d) {
	while (b != e) {
		*d = *b;//d�� cout�ε� ����� ��ġ�� ��ĭ�� �б� ���ؼ� d�� ++�ϰ� �ִ�.
		//�����δ� *d.operator=(*b){
		//	v.push_back(*b); } �̷� Ȱ���� �̷����� �ִ�. ���� �ڵ�, ������ ���ư��� �ڵ�� �ƴ�.
		++b;
		++d;
	}
}



int main()
{
	save("STL.cpp");

	String s{ "20240514 �⸻���� 6�� 15�� 15�� 2��" };
	vector<char> v;
	v.reserve(100);//���Ϳ� �ڸ� 100ĭ�� �ش�. �ڸ��� ���ִϱ� ��������.
	my_copy(s.begin(), s.end(), back_inserter(v));//back_inserter�� �����ϱ� ������ �ȴ�. 
	for (char c : v) {
		cout << c;
	}
	//���Ϳ� �����ʹ� 100% ���µ� �� ����� ����? 
	//�����ʹ� ���µ� ���Ͱ� �����Ͱ� ���� �𸣴ϱ� begin�� end�� ����Ű�� ��ġ�� ����.
	//�׷��� �ƹ� �͵� ������� ���ϰ� �ִ� �Ŵ�.
	//���Ͱ� �츮���� �˷��ذ� �ƴ϶� �츮�� �����ϰ� ���� ��ġ���ٰ� �����Ŵϱ�
	//���ʹ� ������ ������ ���Ұ����� ���� �Ѵ�
}

