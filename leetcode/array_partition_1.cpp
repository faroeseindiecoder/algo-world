#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;

int arrayPairSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int maxSum = 0;
	for (int i = 0; i < nums.size(); i += 2) {
		maxSum += nums[i];
	}
	return maxSum;
}

int main() {
	vector<int> nums = {1, 4, 3, 2};
	assert(arrayPairSum(nums) == 4);
}
