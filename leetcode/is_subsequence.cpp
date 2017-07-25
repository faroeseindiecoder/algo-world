#include<iostream>
#include<cassert>
using namespace std;

bool isSubsequence(string s, string t) {
	if (s == "") {
		return true;
	}

	int sIndex = 0;
	for (int i = 0; i < t.size(); i++) {
		while (i < t.size() && sIndex < s.size() && s[sIndex] != t[i]) {
			i++;
		}
		if (s[sIndex] == t[i]) {
			sIndex++;
		}
	}
	
	if (sIndex == s.size()) {
		return true;
	}
	
	return false;
}

int main() {

	assert(isSubsequence("abc", "ahbgdc") == 1);
	assert(isSubsequence("axc", "ahbgdc") == 0);
	assert(isSubsequence("b", "c") == 0);
	assert(isSubsequence("leeeeetcode", "ylyeyeyeyeyeytycyoydyey") == 1);
	assert(isSubsequence("bcd", "uuuubcd") == 1);
	
}

