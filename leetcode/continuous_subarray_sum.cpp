#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
	if (k == 0) {
		int sumNums = 0;
		for (int i = 0; i < nums.size(); i++) {
			sumNums += nums[i];
		}
		if (sumNums != 0) {
			return false;
		}
		if (nums.size() >= 2) {
			return true;
		}
		return false;
	}
	vector<int> mod (nums.size());
	unordered_map<int, vector<int>> modPositions;
	mod[0] = nums[0] % k;
	vector<int> posFirst = {0};
	modPositions[mod[0]] = posFirst;
	for (int i = 1; i < nums.size(); i++) {
		mod[i] = (mod[i-1] + nums[i]) % k; 
		if (modPositions.find(mod[0]) == modPositions.end()) {
			vector<int> positions = {i};
			modPositions[mod[i]] = positions;
		} else {
			modPositions[mod[i]].push_back(i);
		}
		
		if (mod[i] == 0) {
			return true;
		}
	}
	for (auto &pair : modPositions) {
		if (pair.second.size() >= 2) {
			int firstPosMod = pair.second[0];
			for (int i = 1; i < pair.second.size(); i++) {
				if (pair.second[i] - firstPosMod >= 2) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	vector<int> nums = {23, 2, 6, 4, 7};
	cout << checkSubarraySum(nums, 0) << endl;
	nums = {23, 2, 6, 4, 7};
	cout << checkSubarraySum(nums, 6) << endl;
}
