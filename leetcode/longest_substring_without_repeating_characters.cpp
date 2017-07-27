#include<iostream>
#include<unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
	unordered_set<char> chars;
	int maxLength = 0, nextToDelete = 0;
	for (int i = 0; i < s.length(); i++) {
		if (chars.find(s[i]) == chars.end()) {
			chars.insert(s[i]);
			if (chars.size() > maxLength) {
				maxLength = chars.size();
			}
		} else {
			for (; s[nextToDelete] != s[i]; nextToDelete++) {
				chars.erase(s[nextToDelete]);
			} 
			nextToDelete++;
		}
	}
	
	return maxLength;
}

int main() {
	string s = "abcabcabac";
	cout << lengthOfLongestSubstring(s) << endl;

}
