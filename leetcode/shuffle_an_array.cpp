#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
private:
	vector<int> arr;
public:
	Solution(vector<int> nums) {
		arr = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return arr;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		int lastIndex = arr.size() - 1;
		int n = arr.size();
		vector<int> shuffledArr = arr;
		while (lastIndex >= 1) {
			int randIndex = rand() % n;
			int randElem = shuffledArr[randIndex];
			shuffledArr[randIndex] = shuffledArr[lastIndex];
			shuffledArr[lastIndex] = randElem;
			lastIndex--;
			n--;
		}
		return shuffledArr;
	}
};

int main() {

	vector<int> nums = {1, 2, 3};
	Solution *obj = new Solution(nums);
	vector<int> param_2 = obj->shuffle();
	for (int i = 0; i < param_2.size(); i++) {
		cout << param_2[i] << " ";
	}
	cout << endl;
	vector<int> param_1 = obj->reset();
	for (int i = 0; i < param_1.size(); i++) {
		cout << param_1[i] << " ";
	}
	cout << endl;

}
