#include<iostream>
#include<ctype.h>
#include<vector>
using namespace std;

int extractMaxNumericValue(string str) {
	string s = "";
	int i = 0;
	vector<int> v;
	while (i < str.length()) {
		if (isdigit(str[i]))
			s += str[i];
		else {
			if (s != "") {
				v.push_back(atoi(s.c_str()));
				s = "";
			}
		}
		i++;
	}
	if (s != "")
		v.push_back(atoi(s.c_str()));
		
	int max = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > max)
			max = v[i];
	}
	return max;
}

int main() {
	int nrTests;
	string str;
	cin >> nrTests;
	for (int i = 0; i < nrTests; i++) {
		cin >> str;
		cout << extractMaxNumericValue(str) << endl;
	}

}
