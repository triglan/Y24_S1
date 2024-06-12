#include <iostream>
#include "save.h"
#include "string.h"
#include <map>
#include <fstream>
using namespace std;
extern bool 관찰;


int main()
{
    //[문제] : "이상한 나라의 앨리스.txt" 파일을 한 번 읽어서 
    //소문자와 출현 횟수를 다음과 같이 출력하라. 대문자는 모두 소문자로.
    //a - 333개, b - 454개... z - 52개

    ifstream in{ "이상한 나라의 앨리스.txt" };
    if (not in)return 0;

    map<char, int> m;
    char c;
    while (in >> c) {//파일 내용 저장하기 맵을 이용해서
        if (isalpha(c))
            m[tolower(c)]++;	//c를 key값으로 넣는다. 해당 소문자 key값을 계속 ++해줌
    }
    for (auto [소문자, 개수] : m) // 구조화한 binding
        cout << 소문자 << " - " << 개수 << endl;

    // [문제] 개수 내림차수으로 출력하라.
    // 1. 벡터에다가 옮겨서 sort하는 방법도 있다.
    // 2. 지금하는거 개수를 key값으로 map을 하나 만들어 보자
    map<int, char> icm;//less<int>가 디폴트로 숨어있기 때문에 오름차순으로 정렬되고 있었다.
    //greater이라고 하면 내림차순으로 정렬될 것이다.
    for (auto [소문자, 개수] : m)
        icm[개수] = 소문자;

    cout << "개수 기준으로 정렬한 결과" << endl;

    //+ 이번엔 역방향으로 출력한다.
    for (auto p = icm.rbegin(); p != icm.rend(); ++p)
        cout << p->second << " - " << p->first << endl;//


}