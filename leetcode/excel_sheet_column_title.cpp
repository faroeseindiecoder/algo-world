#include<iostream>
#include<cassert>
using namespace std;

//A (65) 1, B (66) 2, ..., Z (91) 26
string toStr(int n) {
	if (n == 0)
		return string(1, 'Z');
	return string(1, n + 'A' - 1);
}

string convertToTitle(int n) {
	
	if (n <= 26) {
		return toStr(n);
	}
	string firstChars = convertToTitle((n-1)/26);
	string lastChar = convertToTitle(n%26);
	return firstChars + lastChar;
}

int main() {
	assert(convertToTitle(53) == "BA");
	assert(convertToTitle(52) == "AZ");
	assert(convertToTitle(27) == "AA");
}
