#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> findMode(TreeNode* root) {
		vector<int> modes;
		unordered_map<int, int> numCount;
		if (root == nullptr) {
			return modes;
		}
		queue<TreeNode*> q;
		q.push(root);
		
		while (1) {
			int numNodesCurrentLevel = q.size();
			if (numNodesCurrentLevel == 0) {
				break;
			}
			while (numNodesCurrentLevel > 0) {
				TreeNode *n = q.front();
				numCount[n->val]++;
				q.pop();
				if (n->left != nullptr) {
					q.push(n->left);
				}
				if (n->right != nullptr) {
					q.push(n->right);
				}
				numNodesCurrentLevel--;			
			}
		}
		
		int maxCount = 0;
		for (auto &pair : numCount) {
			if (pair.second > maxCount) {
				maxCount = pair.second;
			}
		}
		for (auto & pair : numCount) {
			if (pair.second == maxCount) {
				modes.push_back(pair.first);
			}
		}
		
		return modes;
	}
};

int main() {
	TreeNode *t = new TreeNode(1);
	t->right = new TreeNode(2);
	t->right->left = new TreeNode(2);
	vector<int> v = (new Solution)->findMode(t);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}
