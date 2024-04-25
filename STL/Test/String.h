//-----------------------------------------------------------------------------------
// String.h		STL ������ �����ϱ� ���� Ŭ����
// 
// 2024.04.02	���� 
// 2024.04.15 noexcept -> �˻� ����? ������ ���� ���
// 2024.04.16 operator== 
//-----------------------------------------------------------------------------------
#pragma once
#include <memory>
#include <iostream>

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
	bool operator==(const String& rhs);

	// sort���� ����ϱ� ���� getLen - 2024.04.02
	size_t getLen() const;

	// p�� ����Ű�� �޸𸮸� �˷��ش� - 2024.04.02
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