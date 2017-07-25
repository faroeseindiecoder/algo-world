#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

void minMoves2(vector<int>& nums) {
	int k, minMoves = 0;
	if (nums.size() % 2 == 0) {
		k = (nums.size() - 1) / 2; 
	} else {
		k = nums.size() / 2;
	}
	nth_element(nums.begin(), nums.begin() + k, nums.end());
	int median = nums[k];
	for (int i = 0; i < nums.size(); i++) {
		minMoves += abs(median - nums[i]);
	}
	return minMoves;
}

int main() {
	vector<int> nums = {1, 3, 2};
	minMoves2(nums);

}
