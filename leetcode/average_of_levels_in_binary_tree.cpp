#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<double> averageOfLevels(TreeNode* root) {
	vector<double> averages;

	queue<TreeNode*> q;
	q.push(root);
	
	while (1) {
		int currentLevelNodeCount = q.size();
		if (currentLevelNodeCount == 0)
			break;
			
		int numNodesCurrentLevel = currentLevelNodeCount;
		long sumNodesCurrentLevel = 0;
		
		while (currentLevelNodeCount > 0) {
			TreeNode *elem = q.front();
			q.pop();
			sumNodesCurrentLevel += elem->val;
			if (elem->left != nullptr)
				q.push(elem->left);
			if (elem->right != nullptr)
				q.push(elem->right);
			currentLevelNodeCount--;
		}
		averages.push_back((double)sumNodesCurrentLevel/numNodesCurrentLevel);
	}
	return averages;
}

int main() {
	TreeNode *a1 = new TreeNode(2);
	TreeNode *a2 = new TreeNode(1);
	TreeNode *a3 = new TreeNode(15);
	TreeNode *a4 = new TreeNode(12);
	TreeNode *a5 = new TreeNode(5);
	
	a1->left = a2;
	a1->right = a3;
	a2->left = a4;
	a2->right = a5;
	
	vector<double> averages = averageOfLevels(a1);
	for (int i = 0; i < averages.size(); i++)
		cout << "Level " << i << " : " << averages[i] << endl;
}

