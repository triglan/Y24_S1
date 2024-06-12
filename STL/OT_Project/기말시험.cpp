//-----------------------------------------------------------------------------
// 2024 STL �⸻����
// 
// Visual Studio ���� 17.9.0 �̻� 
// Release / x64
// ������Ʈ �Ӽ� - C++ ��� ǥ�� - �ֽ� C++ �ʾ��� ���(/std:c++latest)
//-----------------------------------------------------------------------------
// ���� �ۼ� ���
// - �� ������ �ذ��ϴ� �� �ʿ��� �ڵ常 ���´�.
// - ȭ�鿡 ����� �䱸�ϴ� ������ ��µ� ������ ������ ���´�.
// - ��� ������ ���� �ʿ�� ����.
//-----------------------------------------------------------------------------

#include <algorithm>
#include <array>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <print>
#include <random>
#include <ranges>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

default_random_engine dre;
normal_distribution ndWord{ 0.0, 0.23 };			// �ܾ��� ����
normal_distribution ndSentence{ 0.0, 0.33 };		// ������ ����
uniform_int_distribution<int> uidC{ 'a', 'z' };

//-------------------------------------------------------------------------------------------
// �� ������ �𸣴� ������ "�⸻����.txt" ���Ͽ� �����Ͽ���.
// 
// [�� ���迡�� ������ ����] 
// �ϳ��� ������ 1�� �̻��� �ܾ�(std::string)�� �����Ǹ� �� �ܾ�� �������� ������ �ִ�.
//
// �� ����� �� ���� ������ �������� ���еȴ�.
// 
// ���Ͽ���, ������ �̷�� �ܾ��� ������ ���� �� �Ŀ� �� �ܾ �������� �и��Ͽ� ����Ͽ���.
//-------------------------------------------------------------------------------------------
// ������ ���� ��������. 
//
// [������ ����]
// stl algorithm   
// Comments serve as a sort of in-code documentation 
// heozyz zzeszzycmu uwynruaj 
//
// [���Ͽ� ������ ����]
// 2 stl algorithm   
// 8 Comments serve as a sort of in-code documentation 
// 3 heozyz zzeszzycmu uwynruaj 
//-------------------------------------------------------------------------------------------
template <typename Iterator>
Iterator REVERSE(Iterator begin) {
	auto end = begin;
	while (end != begin.base()) {
		++end;
	}
	return end;
}
//---------
int main( )
//---------
{
	ifstream in{ "�⸻����.txt" };
	
	if (not in) {
		cout << "�⸻����.txt - ������ �� �� �����ϴ�" << endl;
		return -1;
	}


	//--------------------------------------------------------------------------
	// [���� 1] ���Ͽ� ����� ��� ������ �о� STL Container�� �����϶�.	
	// ��� �� ���� ������ �о��� �� ȭ�鿡 ����ϰ� �������� �����.       (40)
	//--------------------------------------------------------------------------
	// ������ �о� �����̳ʿ� �����ϱ� ���� �ڵ带 ������ �����.
	// ����� �����̳� / �а� �����ϴ� �ڵ� / ���� �� ��� �ڵ�  / ��µ� ��
	//
	// (����) ������ ��� �б� ������ �� ���� ������ �ִ� �� �� �� ����.
	// (����) ������ ǥ���ϴ� class�� �ۼ����� �ʰ� �� ������ �ذ��� �� �ִ�.
	// (�κ� ����) ������ class�� �ۼ��� ��� 20������ ä��
	//--------------------------------------------------------------------------

	// ���⿡ 1�� ������ ���� �ڵ��Ѵ�

	//map<string, int> Sim;
	//string s;

	//int cnt{};
	//while (in >> s) {
	//	Sim[s]++;
	//	if(s.)
	//}

	//cout << "�ܾ� ���� - " << Sim.size() << endl;

	vector<vector<string>> st;
	string word;
	while (in >> word) {
		int word_count = stoi(word); // ù ��° �ܾ�� ����
		vector<string> sentence;
		for (int i = 0; i < word_count; ++i) {
			in >> word;
			sentence.push_back(word);
		}
		st.push_back(sentence);
	}

	cout << "������ ����: " << st.size() << endl;

	//--------------------------------------------------------------------------
	// [���� 2] �� ������ ��� �� ���� �ܾ�� �����Ǵ� �� ����϶�.	
	// ��� �ܾ� ���� ȭ�鿡 ����ϰ� �������� �����.                      (20)
	//--------------------------------------------------------------------------
	// �� ������ �ܾ� ���� ���� �� [���� 1]���� ���� ���� ���� ������ �ȴ�.
	// ����� ���ϴ� �ڵ� / ���� ����ϴ� �ڵ� / ��µ� ��
	//
	// (�κ� ����) �˰����� ������� �ʰ� �հ踦 ��� �� ��� 10������ ä��
	//--------------------------------------------------------------------------

	// ���⿡ 2�� ������ ���� �ڵ��Ѵ�

	int total = accumulate(st.begin(), st.end(), 0,
		[](int sum, const vector<string>& sentence) {
			return sum + sentence.size();
		});

	double avg = static_cast<double>(total) / st.size();

	cout << "��� �ܾ� ��: " << avg << endl;





	//---------------------------------------------------------------------------
	// [���� 3] ��ü ���忡 ����� ��� �ܾ��� ��� ���̸� ����϶�.	
	// ��� ���̸� ȭ�鿡 ����ϰ� �������� �����.                          (20)
	//---------------------------------------------------------------------------
	// �ܾ��� ���̴� �� �״�� std:string::size() �Ǵ� std::string::length() ��.
	// �� ���忡 �ִ� �ܾ��� ���̸� ��� ���� �� ��� �ܾ��� ������ ������. 
	// ��� �ܾ��� ������ [���� 2]���� �̹� ����Ͽ���.
	// ��� ���̸� ���ϴ� �ڵ� / ���� ����ϴ� �ڵ� / ��µ� ��
	// 
	// (�κ� ����) �˰����� ������� �ʰ� �հ踦 ��� �� ��� 10�� ä��
	//---------------------------------------------------------------------------

	// ���⿡ 3�� ������ ���� �ڵ��Ѵ�


	int total_length = accumulate(st.begin(), st.end(), 0,
		[](int sum, const vector<string>& sentence) {
			return sum + accumulate(sentence.begin(), sentence.end(), 0,
			[](int sum, const string& word) {
					return sum + word.size();
				});
		});

	double avg_length = static_cast<double>(total_length) / total;

	cout << "��� �ܾ� ����: " << avg_length << endl;



	//------------------------------------------------------------------
	// ���� �����̳ʿ� �ִ� ��� �ܾ vector<string> words�� �����϶�.
	// ����� �˾Ƽ� �ϰ� ������ ���� �ʾƵ� �ȴ�.
	//------------------------------------------------------------------
	// ���� �������� �ذ����� ���� �л��� ������ string�� 100�� �����Ͽ�
	// vector<string> �����̳ʿ� ������ �� ���� ������ �ذ��ϸ� �ȴ�.
	//------------------------------------------------------------------

	vector<string> words;


	// ���⿡�� words�� ���忡 �ִ� string�� �����Ѵ�.

	// ���� words���� ���Ͽ� �ִ� ��� �ܾ ���� ������� ����Ǿ� �ִ�.

	for (const auto& sentence : st) {
		words.insert(words.end(), sentence.begin(), sentence.end());
	}

	//--------------------------------------------------------------
	// ������ words�� ����� �ܾ 20���� ����� �ڵ�� �� ����̴�
	// �ڽ��� ����� ���� ����
	//--------------------------------------------------------------

	// �տ��� 20�� ȭ�� ��� �ڵ�
	/*
	for (const string& s : words | views::take( 20 ))
		cout << s << " ";
	cout << endl;
	*/

	// �տ��� 20�� ȭ�� ��� ���
	//	heozy zzzeszzycmu uwynruaj wfyrrktttm ehsuaihwb dczvvsd arldjftbuaekm llmqusxtu
	//	dlmuyoiwpvfat vgvnyskxlypo zgivhgay fjxfwgyqumz xshrtktojfo nbkbjnpujyzde asikey
	//	uliwnq girnrst zlscxfnxo nozlcwlpcm zz



	//----------------------------------------------------------------------
	// [���� 4] words�� ������ ��� �ܾ��� ù ���ڸ� �빮�ڷ� ��ȯ�϶�.	(20)
	//----------------------------------------------------------------------
	// ��ȯ �ڵ�
	//
	// (����) �˰����� ������� ���� ��� ���� ����
	//----------------------------------------------------------------------

	// ���⿡ 4�� ������ ���� �ڵ��Ѵ�


	ranges::for_each(words, [](string& word) {
		if (!word.empty()) {
			word[0] = toupper(word[0]);
		}});


	// �տ��� 20�� ȭ�� ��� �ڵ�
	
	for (const string& s : words | views::take( 20 ))
		cout << s << " ";
	cout << endl;
	

	// �տ��� 20�� ȭ�� ��� ���
	//	Heozy Zzzeszzycmu Uwynruaj Wfyrrktttm Ehsuaihwb Dczvvsd Arldjftbuaekm Llmqusxtu
	//	Dlmuyoiwpvfat Vgvnyskxlypo Zgivhgay Fjxfwgyqumz Xshrtktojfo Nbkbjnpujyzde Asikey
	//	Uliwnq Girnrst Zlscxfnxo Nozlcwlpcm Zz



	//--------------------------------------------------------------------------------
	// [���� 5] ������ ���� std::copy�� ȣ���Ͽ� v�� ��� �ܾ �������� �ٲٷ� �Ѵ�.
	// �ʿ��� �ڵ��� �߰��϶�.                                                    (40)
	//--------------------------------------------------------------------------------

	// ���� �ּ����� �����ϰ� �ǵ���� ����� �� �־�� �Ѵ�
	std::copy( words.begin( ), words.end( ), REVERSE( words.begin( ) ) );


	// �տ��� 20�� ȭ�� ��� �ڵ�
	
	for (const string& s : words | views::take( 20 ))
		cout << s << " ";
	cout << endl;
	

	// �տ��� 20�� ȭ�� ��� ���
	//	yzoeH umcyzzsezzZ jaurnywU mtttkrryfW bwhiaushE dsvvzcD mkeaubtfjdlrA utxsuqmlL
	//	tafvpwioyumlD opylxksynvgV yaghvigZ zmuqygwfxjF ofjotktrhsX edzyjupnjbkbN yekisA
	//	qnwilU tsrnriG oxnfxcslZ mcplwclzoN zZ
}