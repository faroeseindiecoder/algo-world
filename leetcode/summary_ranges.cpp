#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
	vector<string> ranges;
	if (nums.empty())
		return ranges;
	string currRange = to_string(nums[0]);
	int currRangeCount = 1, lastAddedIndex = 0;
	for (int i = 1; i < nums.size(); i++) {
		while (nums[i] - nums[i-1] == 1) {
			i++;
			currRangeCount++;
		}
		if (currRangeCount > 1) {
			if (nums[i] - nums[i-1] != 1) {
				currRange += "->" + to_string(nums[i-1]);
				lastAddedIndex = i-1;
			}
			else {
				currRange += "->" + to_string(nums[i]);
				lastAddedIndex = i;
			}
		} 
		ranges.push_back(currRange);
		currRange = to_string(nums[i]);
		currRangeCount = 1;
	}
	if (lastAddedIndex == 0 || lastAddedIndex == nums.size() - 2) {
		ranges.push_back(currRange);
	}
	return ranges;
}

int main() {
	vector<int> nums = {0,1,2,4,5,7};
	vector<string> ranges = {"0->2","4->5","7"};
	assert(summaryRanges(nums) == ranges);
	nums = {};
	ranges = {};
	assert(summaryRanges(nums) == ranges);
	nums = {0};
	ranges = {"0"};
	assert(summaryRanges(nums) == ranges);
}
