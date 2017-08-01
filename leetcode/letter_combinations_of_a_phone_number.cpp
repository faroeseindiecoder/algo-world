#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<char, vector<char>> getDigitToLetters() {
	unordered_map<char, vector<char>> digitToLetters;
	digitToLetters['1'] = {'\0'};
	char start = 'a';
	for (char digit = '2'; digit <= '9'; digit++) {
		vector<char> letters;
		if (digit == '7' || digit == '9') {
			for (char j = start; j < start + 4; j++) {
				letters.push_back(j);
			}
			start += 4;
		} else {
			for (char j = start; j < start + 3; j++) {
				letters.push_back(j);
			}
			start += 3;
		}
		digitToLetters[digit] = letters;
	}
	return digitToLetters;
}

void getCombinations(string s, string &digits, int ithDigit, unordered_map<char, vector<char>> &digitToLetters, vector<string> &combinations) {
	if (s.length() == digits.length()) {
		combinations.push_back(s);
		return;
	} else {
			vector<char> letters = digitToLetters[digits[ithDigit]];
			for (int i = 0; i < letters.size(); i++) {
				s += letters[i];
				getCombinations(s, digits, ithDigit + 1, digitToLetters, combinations);
				s.pop_back();
			}
		}
}


vector<string> letterCombinations(string digits) {
	vector<string> combinations;
	if (digits.empty()) {
		return combinations;
	}
	unordered_map<char, vector<char>> digitToLetters = getDigitToLetters();
	string s = "";
	getCombinations(s, digits, 0, digitToLetters, combinations);
	return combinations;
}

int main() {
	vector<string> combinations = letterCombinations("23");
	for (int i = 0; i < combinations.size(); i++) {
		cout << combinations[i] << " ";
	}
	cout << endl;
}
