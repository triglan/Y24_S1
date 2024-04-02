//-------------------------------------------------------
// String.cpp STL ������ �����ϱ� ���� Ŭ����
// 
// 2024/4/2 ����
//-------------------------------------------------------
#include "String.h"
//������ ���� �߰� - 2024.4.2
bool ����{ false };//������ ���ϸ� true�� �ٲ���

size_t String::uid{};// class (private)Static ���� �ʱ�ȭ


//����Ʈ ������2024.4.2
String::String()
    : id{ ++uid }
{
    if (����)
        std::cout << "[" << id << "] - ����, ���� -" << len << ", �ּ� - " << (void*)p.get() << std::endl;

}


// ������
String::String(const char* s)
    : len(strlen(s)), id{ ++uid }
{
    p = std::make_unique<char[]>(len);
    memcpy(p.get(), s, len);
    if (����)
        std::cout << "[" << id << "] - ����(char*), ���� -" << len << ", �ּ� - " << (void*)p.get() << std::endl;
}

String::~String() {
    if (����)
        std::cout << "[" << id << "] - �Ҹ� ���� -" << len << ", �ּ� - " << (void*)p.get() << std::endl;
}


//��������� �����Ҵ� - 2024.4.2
String::String(const String& other)
    : len(other.len), id{ ++uid }
{
    p = std::make_unique<char[]>(len);
    memcpy(p.get(), other.p.get(), len);
    if (����)
        std::cout << "[" << id << "] - �������(char*), ���� -" << len << ", �ּ� - " << (void*)p.get() << std::endl;

}



String& String::operator = (const String& rhs)
{
    if (this == &rhs)
        return *this;

    p.release();

    len = rhs.len;
    p = std::make_unique<char[]>(len);

    memcpy(p.get(), rhs.p.get(), len);
    if (����)
        std::cout << "[" << id << "] - �����Ҵ�, ���� -" << len << ", �ּ� - " << (void*)p.get() << std::endl;

    return *this;
}

//�̵������� �̵��Ҵ� -2024.4.2
String::String(String&& other)
    :len(other.len), id{ ++uid } {
    p.reset(other.p.release());
    if (����)
        std::cout << "[" << id << "] - �̵�����, ���� -" << len << ", �ּ� - " << (void*)p.get() << std::endl;
}
String& String::operator=(String&& other) {
    if (this == &other) return *this;
    p.reset();
    len = other.len;
    p.reset(other.p.release());
    if (����)
        std::cout << "[" << id << "] - �̵��Ҵ�, ���� -" << len << ", �ּ� - " << (void*)p.get() << std::endl;
    return *this;
}
size_t String::getLen() const {
    return len;
}

char* String::getMem() const {
    return p.get();
}