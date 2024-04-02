//-------------------------------------------------------
// String.h STL 동작을 관찰하기 위한 클래스
// 
// 2024/4/2 시작
//-------------------------------------------------------

#pragma once
#include <memory>
#include <iostream>


class String {
    size_t len{};
    std::unique_ptr<char[]> p;//-> 딜리트 복사 생성자 안디게 하고 있음. 얘덕에 굳이 소멸자 없어도됌.
    size_t id{};
public:
    //디폴트 생성자2024.4.2
    String();

    String(const char* s);
    //소멸자를 관찰하려고 코딩했다. - 2024-4-2
    ~String();
    //복사생성과 복사할당 - 2024.4.2
    String(const String&);
    String& operator = (const String&);
    //이동 생성과 이동 할당 -2024.4.2
    String(String&&);
    String& operator=(String&&);


    //sort 용 getLen 2024.4.2
    size_t getLen() const;

    //p가 가리키는 메모리를 알려준다 - 2024. 4. 2
    char* getMem() const;

    friend std::ostream& operator<<(std::ostream& os, const String& s) {
        for (size_t i = 0; i < s.len; ++i)
            os << s.p.get()[i];
        return os;
    }

private:
    static size_t uid; // -> 이거 꼭 확인하기

};