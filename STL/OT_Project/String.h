//-----------------------------------------------------------------------------------
// String.h		STL 동작을 관찰하기 위한 클래스
// 
// 2024.04.02	시작 
// 2024.04.15 noexcept -> 검사 없이? 돌리기 성능 향상
// 2024.04.16 operator==
// 2024.04.30 operator<  
// 2024.05.07 begin(), end()
// 2024.05.07 rbegin(), rend()의 결과는 class 객체이어야 한다.
// 2024.05.13 String_iterator가 진짜 random_access 반복자가 되도록 코딩
//-----------------------------------------------------------------------------------
#pragma once
#include <memory>
#include <iostream>

//String이 제공하는 반복자 - 반복자 iterator
class String_iterator {
public:
	using difference_type = ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

	// C++17
	using iterator_concept = std::contiguous_iterator_tag;
private:
	char* p;
public:
	String_iterator(char* p) : p{p} { }

	char* operator++() {
		return ++p;
	}
	//char operator*() {
	//	return *(p - 1);
	//}
	bool operator == (const String_iterator& rhs)const {
		return p == rhs.p;
	}

	//2024.05.13
	difference_type operator-(const String_iterator& rhs)const {
		return p - rhs.p;
	}
	reference operator*() {
		return *p;
	}
	reference operator*( ) const {// TODO: 한번 해봐x
		return *p;
	}

	String_iterator& operator --() {
		--p;
		return *this;
	}

	String_iterator operator+(difference_type d)const {
		return p + d;
	}

	bool operator<(const String_iterator& rhs)const {
		return p < rhs.p;
	}//이런거 면접 연습 하고 있어

	String_iterator operator-(difference_type d)const {
		return p - d;
	}
};


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
	// 예외를 던지지 않음을 보장 noexcept - 2024.04.15 TODO::
	String(String&&) noexcept;
	String& operator=(String&&) noexcept;

	//연산자 오버로딩
	//2024.04.16 ==, string은 글자수, 내용이 같아야 한다.
	bool operator==(const String& rhs) const;

	//2024.04.30 <
	bool operator<(const String& rhs)const;

	// sort에서 사용하기 위한 getLen - 2024.04.02
	size_t getLen() const;

	// p가 가리키는 메모리를 알려준다 - 2024.04.02
	char* getMem() const;

	//2024.5.7
	String_iterator begin() const {
		return String_iterator{ p.get() };
	}
	String_iterator end() const {
		return String_iterator{ p.get() + len };
	}

	

	String_iterator rbegin() const {
		return String_iterator{ p.get() + len };
	}
	String_iterator rend() const {
		return String_iterator{ p.get() };
	}

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
