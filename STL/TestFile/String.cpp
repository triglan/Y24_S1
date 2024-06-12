//-----------------------------------------------------------------------------------
// String.cpp	STL ������ �����ϱ� ���� Ŭ����
// 
// 2024.04.02	���� 
// 2024.04.15 ���ܸ� ������ ������ ���� noexcept
// 2024.04.30 ������ operator <
//-----------------------------------------------------------------------------------
#include <algorithm>//2024.04.16 equal
#include "String.h"

// ������ ���� �߰� - 2024.04.02
bool ����{ false };			// ������ ���ϸ� true�� �ٲ���

size_t String::uid{ };		// class static ���� �ʱ�ȭ

// ����Ʈ ������ - 2024.04.02
String::String()
	: id{ ++uid }
{
	if (����)
		std::cout << "[" << id << "] - ����(), ���� - " << len << ", �ּ� - " << (void*)p.get() << std::endl;
}

// ������
String::String(const char* s)
	: len(strlen(s)), id{ ++uid }
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), s, len);
	if (����)
		std::cout << "[" << id << "] - ����(char*), ���� - " << len << ", �ּ� - " << (void*)p.get() << std::endl;
}

// �Ҹ��ڴ� �����Ϸ��� �ڵ��� - 2024.04.02
String::~String()
{
	if (����)
		std::cout << "[" << id << "] - �Ҹ�, ���� - " << len << ", �ּ� - " << (void*)p.get() << std::endl;
}


// ��������� �����Ҵ� - 2024.04.02
String::String(const String& other)
	: len(other.len), id{ ++uid }	
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);
	if (����)
		std::cout << "[" << id << "] - �������, ���� - " << len << ", �ּ� - " << (void*)p.get() << std::endl;
}

String& String::operator=(const String& rhs)
{
	if (this == &rhs)
		return *this;

	p.release();

	len = rhs.len;
	p = std::make_unique<char[]>(len);

	memcpy(p.get(), rhs.p.get(), len);
	if (����)
		std::cout << "[" << id << "] - �����Ҵ�, ���� - " << len << ", �ּ� - " << (void*)p.get() << std::endl;

	return *this;
}

// �̵������� �̵��Ҵ� - 2024.04.02
// ���ܸ� ������ ������ ���� noexcept - 2024.04.15 TODO::

String::String(String&& other) noexcept
	: len(other.len), id(++uid)
{
	p.reset(other.p.release());	// �����ض�
	if (����)
		std::cout << "[" << id << "] - �̵�����, ���� - " << len << ", �ּ� - " << (void*)p.get() << std::endl;
}

String& String::operator=(String&& other) noexcept
{
	if (this == &other)
		return *this;

	p.reset();

	len = other.len;

	p.reset(other.p.release());	// �����ض�
	if (����)
		std::cout << "[" << id << "] - �̵��Ҵ�, ���� - " << len << ", �ּ� - " << (void*)p.get() << std::endl;

	return *this;
}

//������ �����ε�
//2024.04.16 ==, string�� ���ڼ�, ������ ���ƾ� �Ѵ�.
bool String::operator==(const String& rhs) const{
	if (len != rhs.len)
		return false;
	// ��x
	return std::equal(p.get(), p.get() + len, rhs.p.get());
}

//2024.04.30 < �� �ϰ� ������ �� �� �ִ� �Լ�
bool String::operator<(const String& rhs)const {
	return std::lexicographical_compare(p.get(), p.get() + len,
		rhs.p.get(), rhs.p.get() + rhs.len);
}

// sort���� ����ϱ� ���� getLen - 2024.04.02
size_t String::getLen() const
{
	return len;
}

// p�� ����Ű�� �޸𸮸� �˷��ش� - 2024.04.02
char* String::getMem() const
{
	return p.get();
}

// 2024.04.09
std::istream& operator>>(std::istream& is, String& s)
{
	std::string ts;
	is >> ts;
	s.len = ts.size();
	s.p = std::make_unique<char[]>(s.len);
	memcpy(s.p.get(), ts.data(), s.len);

	return is;
}