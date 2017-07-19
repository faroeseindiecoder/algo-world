#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
	int startIndex = 0, endIndex = k-1;
	int sum = 0;
	for (int i = 0; i < k; i++) {
		sum += nums[i];
	}
	int maxSum = sum;
	while (endIndex + 1 < nums.size()) {
		sum -= nums[startIndex++];
		sum += nums[endIndex+1];
		endIndex++;
		if (sum > maxSum)
			maxSum = sum;
	}
	return (double)maxSum/k;
}


int main() {
	vector<int> nums = {1,12,-5,-6,50,3};
	int k = 4;
	assert(findMaxAverage(nums, k) == 12.75);

}
