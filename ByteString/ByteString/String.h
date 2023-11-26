#pragma once
#include <iostream>
using namespace std;
class String
{
protected:
	char* str;
	static size_t CountStr;
public:
	String();
	String(size_t size);
	String(const char* str);
	String(const String& OtherString);
	~String();

	void SetStr(char* str);
	char* GetStr() const;
	size_t GetLenStr() const;

	static size_t GetCountStr();

	void clear();

	String& operator=(const String& OtherString) noexcept;
	String operator*(const String& OtherString) noexcept;
	String operator+(const String& OtherString) const;
	String& operator+=(const String& OtherString) noexcept;
	bool operator==(const String& OtherString) const;
	bool operator!=(const String& OtherString) const;
};

inline ostream& operator<<(ostream& out, const String& string) {
	out << string.GetStr();
	return out;
}

inline istream& operator>>(istream& in, String& string) {
	char Buffer[200];
	in.getline(Buffer, strlen(Buffer));
	string.SetStr(Buffer);
	return in;
}
