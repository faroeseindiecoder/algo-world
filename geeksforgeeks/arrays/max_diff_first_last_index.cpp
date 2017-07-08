#include<iostream>
#include<map>
#include<vector>
#include<utility>
using namespace std;

int maxDiffFirstLastIndex(vector<int> &v) {
	map<int, pair<int, int>> m;
	for (int i = 0; i < v.size(); i++) {
		map<int, pair<int, int>>::iterator it = m.find(v[i]);
		if (it == m.end()) {
			m[v[i]] = make_pair(i, i);
		} else {
			pair<int, int> p = m[v[i]];
			m[v[i]] = make_pair(get<0>(p), i);
		}
	}
	int max = 0;
	for (auto &x : m) {
		int diff = get<1>(x.second) - get<0>(x.second);
		if (diff > max) max = diff;
	}
	return max;
}

int main() {
	vector<int> v1 = {2, 1, 3, 4, 2, 1, 5, 1, 7};
	cout << maxDiffFirstLastIndex(v1) << endl;
	vector<int> v2 = {2, 2, 1, 1, 8, 8, 3, 5, 3};
	cout << maxDiffFirstLastIndex(v2) << endl;
}
