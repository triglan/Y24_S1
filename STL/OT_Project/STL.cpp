//#include <iostream>
//#include "save.h"
//#include "String.h"
//#include <fstream>
//
//using namespace std;
////파일읽어서 객체 몇개인지 써라
////제일 큰 객체 찾아라
////왜 그 컨테이너를 사용했느지
////Sort, find, count등 다양한 알고리즘을 사요ㅕㅇ한느 문제들
//int main()
//{
//    ifstream in{ "int값들.txt" };
//    if (not in)
//        exit(0);
//
//    cout << *max_element(istream_iterator<int>{in}, {}) << endl;
//    in.clear();
//    in.seekg(0, ios::beg);
//
//
//    int num, cnt{};
//    while (in >> num)
//        ++cnt;
//    cout << "모두 " << cnt << "개의 int를 읽었다." << endl;
//    
//}   