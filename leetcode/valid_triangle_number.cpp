#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int triangleNumber(vector<int>& nums) {
	if (nums.size() <= 2) {
		return 0;
	}
	sort(nums.begin(), nums.end());
	int triangleNum = 0;
	int i = 0;
	while (nums[i] == 0) {
		i++;
	}
	for (; i < nums.size() - 2; i++) {
		for (int j = i + 1; j < nums.size() - 1; j++) {
			int sumTwoSides = nums[i] + nums[j];
			vector<int>::iterator lower = lower_bound(nums.begin(), nums.end(), sumTwoSides);
			int lowerSumIdx = lower - nums.begin();
			if (nums[lowerSumIdx - 1] < sumTwoSides) {
				triangleNum += lowerSumIdx - 1 - (j + 1) + 1;
			}
		}
	}
	return triangleNum;
}

int main() {

	vector<int> nums = {0, 1, 1, 1};
	cout << triangleNumber(nums) << endl;
	nums = {1, 1, 3, 4};
	cout << triangleNumber(nums) << endl;
	nums = {2, 2, 3, 4};
	cout << triangleNumber(nums) << endl;

}
