#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
	vector<int> prefixSuffixProduct;
	prefixSuffixProduct.push_back(1);
	int prefix = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		prefixSuffixProduct.push_back(prefix);
		prefix *= nums[i];
	}
	int suffixProduct = 1;
	for (int i = nums.size() - 1; i >= 0; i--) {
		prefixSuffixProduct[i] *= suffixProduct;
		suffixProduct *= nums[i];
	}
	return prefixSuffixProduct;
}

int main() {
	vector<int> nums = {1, 2, 3, 4};
	vector<int> prefixSuffixProduct = productExceptSelf(nums);
	for (int i = 0; i < prefixSuffixProduct.size(); i++) {
		cout << prefixSuffixProduct[i] << " ";
	}
	cout << endl;
}
