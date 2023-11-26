#include "ByteString.h"

int main() {
	srand(time(0));
	ByteString byte1;
	byte1.generateByte();
	ByteString byte2;
	byte2.generateByte();
	ByteString byte3 = byte1 + byte2;
	cout << byte1 << " + " << byte2 << " = " << byte3 << endl << endl;
	ByteString byte4;
	byte4.generateByte();
	cout << byte3 << " += " << byte4 << " = ";
	byte3 += byte4;
	cout << byte3 << endl;
}