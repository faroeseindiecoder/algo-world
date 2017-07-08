#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct node {
	int data;
	node *left, *right;
};

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

void inorder(node *root) {
	if (root == nullptr) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

node* deleteNode(node* root, int key) {
	if (root == nullptr)
		return nullptr;
	if (root->data > key) {
		node *nroot = root->left;
		root = nullptr;
		return deleteNode(nroot, key);
	} 
	else if (root->data == key) {
		if (root->right != nullptr) {
			root->right = nullptr;
		}
		return root->left;
	} else {
		if (root->right != nullptr) {
			node *remainder = deleteNode(root->right, key);
			root->right = remainder;
		}
		return root;
	}
}

int main() {
	int nrTests;
	cin >> nrTests;
	for (int i = 0; i < nrTests; i++) {
		int n; 
		cin >> n;
		int arr[n];
		for (int j = 0; j < n; j++) {
			cin >>  arr[j];
		}
		int key;
		cin >> key;
		sort(arr, arr + n);
		node *root = buildBST(arr, 0, n-1);
		node *nroot = deleteNode(root, key);
		inorder(nroot);
		cout << endl;
	}

}
