//-----------------------------------------------------------------------------------
// String.h		STL 동작을 관찰하기 위한 클래스
// 
// 2024.04.02	시작 
//-----------------------------------------------------------------------------------
#pragma once
#include <memory>
#include <iostream>

class String {
	size_t len{};
	std::unique_ptr<char[]> p;

	size_t id{};

public:
	// 디폴트 생성자 - 2024.04.02
	String();

	String(const char* s);

	// 소멸자를 관찰하려고 코딩함 - 2024.04.02
	~String();

	// 복사생성과 복사할당 - 2024.04.02
	String(const String&);
	String& operator=(const String&);

	// 이동생성과 이동할당 - 2024.04.02
	String(String&&);
	String& operator=(String&&);

	// sort에서 사용하기 위한 getLen - 2024.04.02
	size_t getLen() const;

	// p가 가리키는 메모리를 알려준다 - 2024.04.02
	char* getMem() const;

	friend std::ostream& operator<<(std::ostream& os, const String& s) {
		for (size_t i = 0; i < s.len; ++i) {
			os << s.p.get()[i];
		}
		return os;
	}

	// 2024.04.09
	friend std::istream& operator>>(std::istream& is, String& s);

private:
	static size_t uid;
};
