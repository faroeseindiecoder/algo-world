#include<iostream>
#include<cmath>
using namespace std;

struct node {
	int data;
	node *left, *right;
};

//root left right
void preorderTraversal(node *root) {
	if (root == nullptr) return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

//creates balanced binary search tree from array
node* buildBST(int arr[], int start, int end) {
	if (end < start) {
		return nullptr;
	}
	if (start == end) {
		node *leaf = new node;
		leaf->data = arr[start];
		leaf->left = nullptr;
		leaf->right = nullptr;
		return leaf;
	} 
	int rootIndex = floor(start + (end - start)/2);
	int rootElem = arr[rootIndex];
	node *root = new node;
	root->data = rootElem;
	node *rootLeft = buildBST(arr, start, rootIndex - 1);
	node *rootRight = buildBST(arr, rootIndex + 1, end);
	root->left = rootLeft;
	root->right = rootRight;
	return root;
}

int main() {
	int nrTests;
	cin >> nrTests;
	for (int i = 0; i < nrTests; i++) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << endl;
		node *root = buildBST(arr, 0, n-1);
		preorderTraversal(root);
	}
}
