#include<iostream>
#include<unordered_map>
#include<cassert>
using namespace std;

int firstUniqChar(string s) {
	unordered_map<char, int> charCount;
	for (int i = 0; i < s.length(); i++) {
		charCount[s[i]]++;
	}
	for (int i = 0; i < s.length(); i++) {
		if (charCount[s[i]] == 1)
			return i;
	}
	return -1;
}

int main() {
	assert(firstUniqChar("leetcode") == 0);
	assert(firstUniqChar("loveleetcode") == 2);
}
