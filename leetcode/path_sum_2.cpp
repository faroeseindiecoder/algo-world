#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	void getSum(TreeNode *t, int sum, vector<int> currentPath, vector<vector<int>> &paths) {
		if (t == nullptr) {
			return;
		}
		if (t->left == nullptr && t->right == nullptr) { 
			if (sum == t->val) {
				currentPath.push_back(t->val);
				paths.push_back(currentPath);
			} 
			return;
		}
		currentPath.push_back(t->val);
		if (t->left != nullptr) {
			getSum(t->left, sum - t->val, currentPath, paths);
		}
		if (t->right != nullptr)
			getSum(t->right, sum - t->val, currentPath, paths);
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> paths;
		vector<int> currentPath;
		getSum(root, sum, currentPath, paths);
		return paths;
	}	
	
};

int main() {
	TreeNode *t = new TreeNode(5);
	t->left = new TreeNode(4);
	t->right = new TreeNode(8);
	t->left->left = new TreeNode(11);
	t->left->left->left = new TreeNode(7);
	t->left->left->right = new TreeNode(2);
	t->right->left = new TreeNode(13);
	t->right->right = new TreeNode(4);
	t->right->right->left = new TreeNode(5);
	t->right->right->right = new TreeNode(1);

	vector<vector<int>> paths = (new Solution)->pathSum(t, 22);
	for (int i = 0; i < paths.size(); i++) {
		vector<int> path = paths[i];
		for (int j = 0; j < path.size(); j++) {
			cout << path[j] << " ";
		}
		cout << endl;
	}
}
