#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

bool compare_pairs(vector<int> pair1, vector<int> pair2) {
	if (pair1[0] < pair2[0]) {
		return true;
	} else if (pair1[0] == pair2[0]) {
		return pair1[1] <= pair2[1];
	}
	return false;
}

int findLongestChain(vector<vector<int>>& pairs) {
	sort(pairs.begin(), pairs.end(), compare_pairs);
	vector<int> longestChainLengths(pairs.size());
	for (int i = 0; i < pairs.size(); i++) {
		longestChainLengths[i] = 1;
	}
	for (int i = 1; i < pairs.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (pairs[i][0] > pairs[j][1]) {
				if (longestChainLengths[i] < longestChainLengths[j] + 1) {
					longestChainLengths[i] = longestChainLengths[j] + 1;
				}
			}
		}
	}
	int maxChainLength = longestChainLengths[0];
	for (int i = 1; i < longestChainLengths.size(); i++) {
		if (longestChainLengths[i] > maxChainLength) {
			maxChainLength = longestChainLengths[i];
		}
	}
	return maxChainLength;
}

int main() {
	vector<vector<int>> pairs = {{3, 4}, {2, 3}, {1, 2}};
	assert(findLongestChain(pairs) == 2);
	pairs = {{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}};
	assert(findLongestChain(pairs) == 3);
}
