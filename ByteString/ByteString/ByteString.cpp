#include "ByteString.h"

ByteString& ByteString::operator=(const ByteString& OtherString) noexcept
{
	if (this != &OtherString) {
		delete[] GetStr();
		str = _strdup(OtherString.GetStr());
		ValidByte();
	}
	return *this;
}

ByteString ByteString::operator+(const ByteString& OtherString) const
{
	ByteString byte = *this;
	bool memory = 0;
	for (int i = strlen(byte.GetStr()); i >= 0; i--) {
		if (OtherString.GetStr()[i] == ' ') continue;
		if (OtherString.GetStr()[i] == '0') {
			if (byte.GetStr()[i] == '0') {
				switch (memory) {
				case 0:
					continue;
					break;
				case 1:
					byte.GetStr()[i] = '1';
					memory = 0;
					break;
				}
			}
			else {
				switch (memory) {
				case 0:
					continue;
					break;
				case 1:
					byte.GetStr()[i] = '0';
					break;
				}
			}
		}
		if (OtherString.GetStr()[i] == '1') {
			if (byte.GetStr()[i] == '0') {
				byte.GetStr()[i] = '1';
				switch (memory) {
				case 0:
					continue;
					break;
				case 1:
					byte.GetStr()[i] = '0';
					break;
				}
			}
			else if (byte.GetStr()[i] == '1') 
			{ 
				byte.GetStr()[i] = '0';
				switch (memory) {
				case 0:
					break;
				case 1:
					byte.GetStr()[i] = '1';
					break;
				}
				memory = 1;
			}
		}
	}
	return byte;
}

ByteString& ByteString::operator+=(const ByteString& OtherString) noexcept
{
	*this = *this + OtherString;
	return *this;
}

bool ByteString::operator==(const ByteString& OtherString) const
{
	return strcmp(str, OtherString.str) == 0;
}

bool ByteString::operator!=(const ByteString& OtherString) const
{
	return strcmp(str, OtherString.str) != 0;
}

ByteString& ByteString::generateByte()
{
 	for (int i = 0; i < strlen(this->GetStr()); i++) {
		if (this->GetStr()[i] == ' ') continue;
		this->GetStr()[i] = rand() % 2 + '0';
	}
	return *this;
}

void ByteString::ValidByte()
{
	for (size_t i = 0; i < String::GetLenStr(); i++) {
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ') {
			delete[] str;
			str = nullptr;
			break;
		}
	}
}
