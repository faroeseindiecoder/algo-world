#include<iostream>
using namespace std;

string reverse1(string str) {
	for (int i = 0; i < str.length()/2; i++) {
		char temp = str[i];
		str[i] = str[str.length() - 1 - i];
		str[str.length() - 1 - i] = temp;
	}
	return str;
}

string reverse2(string str) {
	string s = "";
	for (int i = str.length() - 1; i >= 0; i--) {
		s += str[i];
	}
	return s;
}

string reverse3(string str) {
	for (int i = 0; i < str.length()/2; i++) {
		str[i] = str[i] ^ str[str.length() - 1 - i];
		str[str.length() - 1 - i] = str[str.length() - 1 - i] ^ str[i];
		str[i] = str[i] ^ str[str.length() - 1 - i];
	}
	return str;
}

int main() {
	string str = "test";
	string s = reverse3(str);
	cout << s << endl;
}
