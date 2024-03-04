//----------------------------------------------------------
// 2024 STL 3.5 �� 9-10��								(1-1)
//
// Visual Studio 17.9.0 �̻�, Release/x64
// Project �Ӽ�/std:c++ latest <== �̸����� �ֽ�, SDL �˻� - NO ����
// 
// ���б� ���Ǹ� �����ϴ� save �����
// ----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

void save( string_view ); // ������ �迭�� �����ͷ� ���Ѵ�? const char[] �̷������� ��������. string����

int main()
{
	std::cout << "STL �Դϴ�." << '\n';

	std::cout << sizeof(string) << endl;

	save("STL.cpp");
}

void save( string_view fileName ) {
	// fileName�� ���� ���Ϸ� ����.
	//ifstream in;
	//cout << sizeof in << endl; // �� �����Ʈ ¥����? ifstream�� 272����Ʈ ��ŭ �����ϳ�
	//cout << addressof( in ) << endl; // �� ��� ��� �ִ�?, ��� ��ȣ�� �־�� �ϳ�.
	//cout << typeid( in ).name() << endl; // �� �ڷ����� ����?

	ifstream in{ fileName.data()}; // ���� �����͸� �����ϰԵȴ�. data�� �б���� ������ ������.
	if (not in) { // !���� not �ʺ��ڿ� �ڵ尡 �� �б� ����.
		cout << fileName << " - ���� ���� ����" << endl;
		exit(0);
	}

	// ������ ������ ���ٿ� ���� ���� ����.
	ofstream out{ "2024 1�б� STL ��910ȭ78 ��������.txt", ios::app }; 
	// output�� �������� ������ ���� ���� ��� x
	// input�� üũ�� �ؾ��Ѵ�.


	// ���� ������ ������ ��� �о� �� ���Ͽ� ���ٿ� ����.
	// SLT �ڷᱸ���� �˰����� �̿��غ���.
	
	// ������ �ð����
	out << endl << endl << endl;
	
	auto now = chrono::system_clock::now();				// epoch�� ���� ������ tick
	auto time = chrono::system_clock::to_time_t(now);	// UTC �ð����� ��ȯ
	auto lt = localtime(&time);//�����͸� ���ڷ� �Ѱ��ָ� �����Ϸ��� �����ϴ� �Ѵ�. �����ð����� ��ȯ

	auto old = out.imbue(locale("ko_KR")); // ��������� ������ �ѱ����� �ٲ۴�.
	// ��¥�� �� ������� ����Ѵ�.
	out << "==============================================" << endl;
	out << fileName << put_time(lt, ", ����ð�: %x %A %X ") << endl;
	out << "==============================================" << endl;
	out.imbue(old); // ���󺹱� ���ö� �귯�� ���� �ٽ� ���󺹱� ��Ű�� �׷� ��. ���� ��ٰ� ������ ��󺹱� �ؾ���

	// ���� �ڵ��� �ƴϴ� ������ ���� ��.
	//���� v�� �ڵ��� ��� ������ ����Ǿ� �ִ�.
	vector<char> v{ istreambuf_iterator<char>{in}, {} };//�ʱ�ȭ�� �غ� ���̴�.

	//for (char c : v)
	//	out << c; <- �̰Դ� ���� �ڵ��� �Ѵ�. �����ϴ� �ڵ��ε�.

	copy(v.begin(), v.end(), ostreambuf_iterator<char>{out}); // �˰����� Ȱ���� �� ������ �ڵ����� �����غ�
	// ������ ���ۺ��� ������ out���Ϸ� �����Ѵ�.
	// ������ ������ ���ٿ��� ����ȴ�.
	
}