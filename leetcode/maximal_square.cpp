#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

int maximalSquare(vector<vector<int>>& matrix) {
	if (matrix.empty()) {
		return 0;
	}
	vector<vector<int>> maxSquare(matrix.size(), vector<int>(matrix[0].size()));
	int maxSide = 0;
	for (int i = 0; i < matrix.size(); i++) {
		if (matrix[i][0] == 1) {
			maxSquare[i][0] = 1;
			if (maxSquare[i][0] > maxSide) {
				maxSide = maxSquare[i][0];
			}
		}
	}
	for (int j = 0; j < matrix[0].size(); j++) {
		if (matrix[0][j] == 1) {
			maxSquare[0][j] = 1;
			if (maxSquare[0][j] > maxSide) {
				maxSide = maxSquare[0][j];
			}
		}
	}
	for (int i = 1; i < matrix.size(); i++) {
		for (int j = 1; j < matrix[0].size(); j++) {
			if (matrix[i][j] == 1) {
				maxSquare[i][j] = min(maxSquare[i-1][j], min(maxSquare[i][j-1], maxSquare[i-1][j-1])) + 1;
				if (maxSquare[i][j] > maxSide) {
					maxSide = maxSquare[i][j];
				}
			}
		}
	}

	return maxSide * maxSide;
}

int main() {
	vector<vector<int>> matrix = {{1, 0, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}};
	assert(maximalSquare(matrix) == 4);
	matrix = {{1}};
	assert(maximalSquare(matrix) == 1);
	matrix = {};
	assert(maximalSquare(matrix) == 0);
}
