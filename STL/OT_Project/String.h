//-----------------------------------------------------------------------------------
// String.h		STL ������ �����ϱ� ���� Ŭ����
// 
// 2024.04.02	���� 
// 2024.04.15 noexcept -> �˻� ����? ������ ���� ���
// 2024.04.16 operator==
// 2024.04.30 operator<  
// 2024.05.07 begin(), end()
// 2024.05.07 rbegin(), rend()�� ����� class ��ü�̾�� �Ѵ�.
// 2024.05.13 String_iterator�� ��¥ random_access �ݺ��ڰ� �ǵ��� �ڵ�
//-----------------------------------------------------------------------------------
#pragma once
#include <memory>
#include <iostream>

//String�� �����ϴ� �ݺ��� - �ݺ��� iterator
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
	reference operator*( ) const {// TODO: �ѹ� �غ�x
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
	}//�̷��� ���� ���� �ϰ� �־�

	String_iterator operator-(difference_type d)const {
		return p - d;
	}
};


class String {
	size_t len{};
	std::unique_ptr<char[]> p;

	size_t id{};

public:
	// ����Ʈ ������ - 2024.04.02
	String();

	String(const char* s);

	// �Ҹ��ڸ� �����Ϸ��� �ڵ��� - 2024.04.02
	~String();

	// ��������� �����Ҵ� - 2024.04.02
	String(const String&);
	String& operator=(const String&);

	// �̵������� �̵��Ҵ� - 2024.04.02
	// ���ܸ� ������ ������ ���� noexcept - 2024.04.15 TODO::
	String(String&&) noexcept;
	String& operator=(String&&) noexcept;

	//������ �����ε�
	//2024.04.16 ==, string�� ���ڼ�, ������ ���ƾ� �Ѵ�.
	bool operator==(const String& rhs) const;

	//2024.04.30 <
	bool operator<(const String& rhs)const;

	// sort���� ����ϱ� ���� getLen - 2024.04.02
	size_t getLen() const;

	// p�� ����Ű�� �޸𸮸� �˷��ش� - 2024.04.02
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
