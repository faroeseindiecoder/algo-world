#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;

struct node {
	int data;
	node *left, *right;
};

node* buildBST(int arr[], int start, int end) {
	if (start > end) return nullptr;
	if (start == end) {
		node *leaf = new node;
		leaf->data = arr[start];
		leaf->left = nullptr;
		leaf->right = nullptr;
		return leaf;
	}
	int rootIndex = floor(start + (end-start)/2);
	int rootElem = arr[rootIndex];
	node *root = new node;
	root->data = rootElem;
	node *rootLeft = buildBST(arr, start, rootIndex-1);
	node *rootRight = buildBST(arr, rootIndex+1, end);
	root->left = rootLeft;
	root->right = rootRight;

	return root;
}

vector<int> getValues(node *root) {
	//dfs
	stack<node*> s;
	s.push(root);
	unordered_map<node*, bool> visited;
	vector<int> values;
	while (!s.empty()) {
		node *n = s.top();
		s.pop();
		values.push_back(n->data);
		if (!visited[n]) {
			if (n->left != nullptr) s.push(n->left);
			if (n->right != nullptr) s.push(n->right);
			visited[n] = true;
		}
	}
	return values;
}

void printCommon(node *root1, node *root2) {
	vector<int> values1 = getValues(root1);
	vector<int> values2 = getValues(root2);
	sort(values1.begin(), values1.end());
	sort(values2.begin(), values2.end());
	vector<int> common;
	set_intersection(values1.begin(), values1.end(), 
					values2.begin(), values2.end(), 
					back_inserter(common));
	for (int elem : common) {
		cout << elem << " ";
	}
}

int main() {
	int nrTests;
	cin >> nrTests;
	for (int i = 0; i < nrTests; i++) {
		int length1;
		cin >> length1;
		int arr1[length1];
		for (int j = 0; j < length1; j++) {
			cin >> arr1[j];
		}
		int length2;
		cin >> length2;
		int arr2[length2];
		for (int j = 0; j < length2; j++) {
			cin >> arr2[j];
		}
		sort(arr1, arr1 + length1);
		sort(arr2, arr2 + length2);
		node* root1 = buildBST(arr1, 0, length1-1);
		node* root2 = buildBST(arr2, 0, length2-1);
		printCommon(root1, root2);
		cout << endl;
	}

}
