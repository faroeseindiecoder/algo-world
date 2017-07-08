#include<iostream>
#include<vector>
using namespace std;

int findLengthLongestNondecreasingSequence(vector<int> &v) {
	vector<int> lengths(v.size());
	for (int i = 0; i < v.size(); i++) {
		lengths[i] = 1;
	}
	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i] && lengths[i] < lengths[j] + 1) 
				lengths[i] = lengths[j] + 1;
		}
	}
	int max = lengths[0];
	for (int i = 0; i < lengths.size(); i++) {
		if (lengths[i] > max)
			max = lengths[i];
	}

	return max;
}

int main() {
	vector<int> v1 = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
	int l1 = findLengthLongestNondecreasingSequence(v1);
	cout << l1 << endl;
	vector<int> v2 = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int l2 = findLengthLongestNondecreasingSequence(v2);
	cout << l2 << endl;
	vector<int> v3 = {5, 3, 4, 8, 6, 7};
	int l3 = findLengthLongestNondecreasingSequence(v3);
	cout << l3 << endl;
}
