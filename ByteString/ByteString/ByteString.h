#pragma once
#include "String.h"

class ByteString : public String
{
public:
	ByteString() : String() { str = _strdup("0000 0000"); }
	ByteString(const char* str) : String(str) { ValidByte(); }
	ByteString(const ByteString& otherStr) : String(otherStr) { ValidByte(); }
	~ByteString() {}

	ByteString& operator=(const ByteString& OtherString) noexcept;
	ByteString operator+(const ByteString& OtherString) const;
	ByteString& operator+=(const ByteString& OtherString) noexcept;
	bool operator==(const ByteString& OtherString) const;
	bool operator!=(const ByteString& OtherString) const;
	ByteString& generateByte();
private:
	void ValidByte();
};

