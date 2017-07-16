#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<algorithm>
#include<cassert>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> findAllSubtreesSum(TreeNode* root) {
	vector<int> v;
	if (root == nullptr) {
		return v;
	}
	if (root->left == nullptr && root->right == nullptr) {
		v.push_back(root->val);
		return v;
	}
	vector<int> vLeft, vRight;
	if (root->left != nullptr) {
		vLeft = findAllSubtreesSum(root->left);
	}
	if (root->right != nullptr) {
		vRight = findAllSubtreesSum(root->right);
	}
	
	vector<int> allSums;
	int sumLeft = 0;
	if (!vLeft.empty()) {
		sumLeft = vLeft[vLeft.size() - 1];
		for (int i = 0; i < vLeft.size(); i++) {
			allSums.push_back(vLeft[i]);
		}
	}
	int sumRight = 0;
	if (!vRight.empty()) {
		sumRight = vRight[vRight.size() - 1];
		for (int i = 0; i < vRight.size(); i++) {
			allSums.push_back(vRight[i]);
		}
	}
	allSums.push_back(sumLeft + root->val + sumRight);
	return allSums;
}

vector<int> findFrequentTreeSum(TreeNode *root) {
	vector<int> allSums = findAllSubtreesSum(root);

	unordered_map<int, int> sumCount;
	for (int i = 0; i < allSums.size(); i++) {
		sumCount[allSums[i]]++;
	}
	int maxCount = INT_MIN;
	for (auto &x : sumCount) {
		if (x.second > maxCount) {
			maxCount = x.second;
		}
	}
	vector<int> sumsWithMaxCount;
	for (auto &x : sumCount) {
		if (x.second == maxCount) {
			sumsWithMaxCount.push_back(x.first);
		}
	}
	return sumsWithMaxCount;
}

int main() {

	TreeNode *a11 = new TreeNode(5);
	TreeNode *a12 = new TreeNode(14);
	TreeNode *a13 = new TreeNode(1);
	a11->left = a12;
	a12->left = a13;
	vector<int> sol1 = {20, 15, 1};
	assert(findFrequentTreeSum(a11) == sol1);
	
	TreeNode *a21 = new TreeNode(0);
	TreeNode *a22 = new TreeNode(-1);
	a21->left = a22;
	vector<int> sol2 = {-1};
	assert(findFrequentTreeSum(a21) == sol2);
	
	TreeNode *a31 = new TreeNode(5);
	TreeNode *a32 = new TreeNode(2);
	TreeNode *a33 = new TreeNode(-3);
	a31->left = a32;
	a31->right = a33;
	vector<int> sol3 = {4, -3, 2};
	assert(findFrequentTreeSum(a31) == sol3);
	
	TreeNode *a41 = new TreeNode(5);
	TreeNode *a42 = new TreeNode(2);
	TreeNode *a43 = new TreeNode(-5);
	a41->left = a42;
	a41->right = a43;
	vector<int> sol4 = {2};
	assert(findFrequentTreeSum(a41) == sol4);
}

