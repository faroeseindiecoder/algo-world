#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
using namespace std;

class Solution {
	public:
		int kthSmallest(vector<vector<int>>& matrix, int k) {
			priority_queue<int, vector<int>, greater<int>> pq;
			for (int i = 0; i < matrix.size(); i++) {
				for (int j = 0; j < matrix[i].size(); j++) {
					pq.push(matrix[i][j]);
				}
			}
			for (int i = 0; i < k - 1; i++) {
				pq.pop();
			}
			return pq.top();
		}
};

int main() {

	vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
	assert((new Solution)->kthSmallest(matrix, 8) == 13);
	matrix = {{-5}};
	assert((new Solution)->kthSmallest(matrix, 1) == -5);

}
