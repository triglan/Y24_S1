//-------------------------------------------------------
// String.h STL ������ �����ϱ� ���� Ŭ����
// 
// 2024/4/2 ����
//-------------------------------------------------------

#pragma once
#include <memory>
#include <iostream>


class String {
    size_t len{};
    std::unique_ptr<char[]> p;//-> ����Ʈ ���� ������ �ȵ�� �ϰ� ����. ����� ���� �Ҹ��� �����.
    size_t id{};
public:
    //����Ʈ ������2024.4.2
    String();

    String(const char* s);
    //�Ҹ��ڸ� �����Ϸ��� �ڵ��ߴ�. - 2024-4-2
    ~String();
    //��������� �����Ҵ� - 2024.4.2
    String(const String&);
    String& operator = (const String&);
    //�̵� ������ �̵� �Ҵ� -2024.4.2
    String(String&&);
    String& operator=(String&&);


    //sort �� getLen 2024.4.2
    size_t getLen() const;

    //p�� ����Ű�� �޸𸮸� �˷��ش� - 2024. 4. 2
    char* getMem() const;

    friend std::ostream& operator<<(std::ostream& os, const String& s) {
        for (size_t i = 0; i < s.len; ++i)
            os << s.p.get()[i];
        return os;
    }

private:
    static size_t uid; // -> �̰� �� Ȯ���ϱ�

};