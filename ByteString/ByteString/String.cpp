#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

size_t String::CountStr = 0;

String::String() {
	str = nullptr;
	CountStr++;
}

String::String(size_t size) {
	str = new char[size];
	CountStr++;
}

String::String(const char* str) {
	this->str = _strdup(str);
	CountStr++;
}

String::String(const String& OtherString) {
	if (OtherString.str) {
		str = _strdup(OtherString.str);
		CountStr++;
	}
}

String::~String() {
	delete[] str;
	CountStr--;
}

void String::SetStr(char* str) {
	delete[] this->str;
	this->str = _strdup(str);
}

char* String::GetStr() const {
	return str;
}

size_t String::GetLenStr() const
{
	return strlen(str);
}

size_t String::GetCountStr() {
	return CountStr;
}

void String::clear()
{
	delete[] str;
	str = nullptr;
}

String& String::operator=(const String& OtherString) noexcept {
	if (this != &OtherString) {
		delete[] str;
		str = _strdup(OtherString.str);
	}
	return *this;
}

String String::operator*(const String& OtherString) noexcept {
	String result;
	int n = 0;
	for (int i = 0; i < (strlen(str) <= strlen(OtherString.str) ? strlen(str) : strlen(OtherString.str)); i++) {
		for (int j = 0; j < (strlen(str) > strlen(OtherString.str) ? strlen(str) : strlen(OtherString.str)); j++) {
			if (str[i] == OtherString.str[j]) {
				result.str[n++] = str[i];
				break;
			}
		}
	}
	result.str[n] = '\0';
	return result;
}

String String::operator+(const String& OtherString) const
{
	String str(GetLenStr() + OtherString.GetLenStr() + 1);
	strcpy(str.GetStr(), this->str);
	strcat(str.GetStr(), OtherString.GetStr());
	return str;
}

String& String::operator+=(const String& OtherString) noexcept
{
	String str = *this + OtherString;
	*this = str;
	return *this;
}

bool String::operator==(const String& OtherString) const
{
	return strcmp(str, OtherString.str) == 0;
}

bool String::operator!=(const String& OtherString) const
{
	return strcmp(str, OtherString.str) != 0;
}
