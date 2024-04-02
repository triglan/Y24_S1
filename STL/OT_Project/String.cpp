//-------------------------------------------------------
// String.cpp STL 동작을 관찰하기 위한 클래스
// 
// 2024/4/2 시작
//-------------------------------------------------------
#include "String.h"
//관찰용 변수 추가 - 2024.4.2
bool 관찰{ false };//관찰을 원하면 true로 바꾸자

size_t String::uid{};// class (private)Static 변수 초기화


//디폴트 생성자2024.4.2
String::String()
    : id{ ++uid }
{
    if (관찰)
        std::cout << "[" << id << "] - 생성, 길이 -" << len << ", 주소 - " << (void*)p.get() << std::endl;

}


// 생성자
String::String(const char* s)
    : len(strlen(s)), id{ ++uid }
{
    p = std::make_unique<char[]>(len);
    memcpy(p.get(), s, len);
    if (관찰)
        std::cout << "[" << id << "] - 생성(char*), 길이 -" << len << ", 주소 - " << (void*)p.get() << std::endl;
}

String::~String() {
    if (관찰)
        std::cout << "[" << id << "] - 소멸 길이 -" << len << ", 주소 - " << (void*)p.get() << std::endl;
}


//복사생성과 복사할당 - 2024.4.2
String::String(const String& other)
    : len(other.len), id{ ++uid }
{
    p = std::make_unique<char[]>(len);
    memcpy(p.get(), other.p.get(), len);
    if (관찰)
        std::cout << "[" << id << "] - 복사생성(char*), 길이 -" << len << ", 주소 - " << (void*)p.get() << std::endl;

}



String& String::operator = (const String& rhs)
{
    if (this == &rhs)
        return *this;

    p.release();

    len = rhs.len;
    p = std::make_unique<char[]>(len);

    memcpy(p.get(), rhs.p.get(), len);
    if (관찰)
        std::cout << "[" << id << "] - 복사할당, 길이 -" << len << ", 주소 - " << (void*)p.get() << std::endl;

    return *this;
}

//이동생성과 이동할당 -2024.4.2
String::String(String&& other)
    :len(other.len), id{ ++uid } {
    p.reset(other.p.release());
    if (관찰)
        std::cout << "[" << id << "] - 이동생성, 길이 -" << len << ", 주소 - " << (void*)p.get() << std::endl;
}
String& String::operator=(String&& other) {
    if (this == &other) return *this;
    p.reset();
    len = other.len;
    p.reset(other.p.release());
    if (관찰)
        std::cout << "[" << id << "] - 이동할당, 길이 -" << len << ", 주소 - " << (void*)p.get() << std::endl;
    return *this;
}
size_t String::getLen() const {
    return len;
}

char* String::getMem() const {
    return p.get();
}