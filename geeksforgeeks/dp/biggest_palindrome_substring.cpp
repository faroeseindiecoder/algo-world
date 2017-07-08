#include<iostream>
#include<cassert>
#include<string>
using namespace std;

//runtime: O(n^2), space O(n)
string getLongestPalindromeSubstring(string s) {

	string longestPalindrome = "";
	string currentPalindrome = "";
	int leftPos, rightPos;

	for (int i = 0; i < s.length(); i++) {
		char centerOfPalindrome = s[i];
		leftPos = i;
		rightPos = i;
		if (rightPos + 1 < s.length() && s[leftPos] == s[rightPos + 1])
			rightPos++;

		while (leftPos >= 0 && rightPos < s.length() && s[leftPos] == s[rightPos]) {
			leftPos--;
			rightPos++;
		}
		leftPos++;
		rightPos--;

		currentPalindrome = s.substr(leftPos, rightPos - leftPos + 1);
			
		if (currentPalindrome.length() > longestPalindrome.length())
			longestPalindrome = currentPalindrome;
	}
	return longestPalindrome;
}

//runtime O(n^3)
string getLongestPalindromeSubstring2(string s) {

	string longestPalindrome = "";
	string currentPalindrome = "";

	for (int i = 0; i < s.length(); i++) {
		for (int j = i; j < s.length(); j++) {
			bool isPalindrome = true;
			for (int k = i; k <= (i + j) / 2; k++) {
				if (s[k] != s[j - k + i])
					isPalindrome = false;
			}
			if (isPalindrome)
				currentPalindrome = s.substr(i, j - i + 1);
			if (currentPalindrome.length() > longestPalindrome.length())
				longestPalindrome = currentPalindrome;
		}
	}

	return longestPalindrome;
}

//dp solution: O(n^2) runtime & O(n^2) space
string getLongestPalindromeSubstring3(string s) {
	int maxSize;
	int startIndexLongestPalindrome;

	if (!s.empty()) {
		maxSize = 1;
		startIndexLongestPalindrome = 0;
	} else {
		return "";
	}
	
	bool **table = new bool*[s.length()];
	for (int i = 0; i < s.length(); i++)
		table[i] = new bool[i];
	
	//palindromes of size 1
	for (int i = 0; i < s.length(); i++)
		table[i][i] = 1;
	
	//palindromes of size 2
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == s[i+1]) {
			table[i][i+1] = 1;
			startIndexLongestPalindrome = i;
			maxSize = 2;
		}
	}

	//for palindromes of size at least 3:
	for (int size = 3; size <= s.length(); size++) {
		for (int i = 0; i + size - 1 < s.length(); i++) {
			int start = i;
			int end = i + size - 1;
			if (table[start + 1][end - 1] == 1 && s[start] == s[end]) {
				table[start][end] = 1;
				if (size > maxSize) {
					maxSize = size;
					startIndexLongestPalindrome = start;
				}
			}
		}
	}
	
	return s.substr(startIndexLongestPalindrome, maxSize);
}

//manacher algorithm: O(n) runtime

int main() {

	assert(getLongestPalindromeSubstring("AABCDCBA") == "ABCDCBA");
	assert(getLongestPalindromeSubstring("DEFABCBAYT") == "ABCBA");
	assert(getLongestPalindromeSubstring("ADCDA") == "ADCDA");
	assert(getLongestPalindromeSubstring("") == "");
	assert(getLongestPalindromeSubstring("A") == "A");
	assert(getLongestPalindromeSubstring("TADA") == "ADA");
	assert(getLongestPalindromeSubstring("ABBA") == "ABBA");
	assert(getLongestPalindromeSubstring("CAT") == "C");
	assert(getLongestPalindromeSubstring("FAAAACBF") == "AAAA");

	assert(getLongestPalindromeSubstring2("AABCDCBA") == "ABCDCBA");
	assert(getLongestPalindromeSubstring2("DEFABCBAYT") == "ABCBA");
	assert(getLongestPalindromeSubstring2("ADCDA") == "ADCDA");
	assert(getLongestPalindromeSubstring2("") == "");
	assert(getLongestPalindromeSubstring2("A") == "A");
	assert(getLongestPalindromeSubstring2("TADA") == "ADA");
	assert(getLongestPalindromeSubstring2("ABBA") == "ABBA");
	assert(getLongestPalindromeSubstring2("CAT") == "C");
	assert(getLongestPalindromeSubstring2("FAAAACBF") == "AAAA");

	assert(getLongestPalindromeSubstring3("AABCDCBA") == "ABCDCBA");
	assert(getLongestPalindromeSubstring3("DEFABCBAYT") == "ABCBA");
	assert(getLongestPalindromeSubstring3("ADCDA") == "ADCDA");
	assert(getLongestPalindromeSubstring3("") == "");
	assert(getLongestPalindromeSubstring3("A") == "A");
	assert(getLongestPalindromeSubstring3("TADA") == "ADA");
	assert(getLongestPalindromeSubstring3("ABBA") == "ABBA");
	assert(getLongestPalindromeSubstring3("CAT") == "C");
	assert(getLongestPalindromeSubstring3("FAAAACBF") == "AAAA");

}

