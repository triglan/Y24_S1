//#include <iostream>
//#include "save.h"
//#include "string.h"
//#include <map>
//#include <fstream>
//#include<ranges>
//using namespace std;
//extern bool 관찰;
//
//
//int main()
//{
//    save("STL.cpp");
//
//    //[문제] : "이상한 나라의 앨리스.txt" 파일을 한 번 읽어서 
//    //단어와 출현횟수를 출력하라 //+
//
//    ifstream in{ "이상한 나라의 앨리스.txt" };
//    if (not in)return 0;
//
//    //몇줄 안되는 코딩으로 되죠?
//    //key값이 단어라서 뭐가 제일 많이 쓰였는지 인간이 찾기 어렵다.
//    map<String, int> Sim;
//    String s;
//    while (in >> s)
//        Sim[s]++;
//
//    //for (const auto& [단어, 개수] : Sim)
//        //cout << 단어 << " - " << 개수 << endl;
//
//    //[문제] 많이 사용된 단어 순으로 출력하라.
//    //교수ver, 근데 이건 0점짜리같지? 답지에 이렇게 쓰면 0점이다.
//    //겹칠 수 있으니 multi를 써라 +
//    //근데 multi를 쓰는 순간 iSm같은 연산자를 제공하지 않는다.
//    //그랫 insert make_pair 아래와 같이 써야한다.
//    multimap<int, String> iSm;
//    for (const auto& [단어, 개수] : Sim)
//        iSm.insert(make_pair(개수, 단어));//++ 이거 시험에 나올듯
//
//    cout << "많이 사용된 단어 순" << endl;
//    for (const auto& [개수, 단어] : iSm | views::reverse)//String은 const auto& 넣는듯
//        cout << 단어 << " - " << 개수 << endl;
//}