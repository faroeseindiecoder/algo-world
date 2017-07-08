#include<iostream>
#include<cmath>
#include<algorithm>

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

node* deleteNodeRecursive(node *root, int x) {
	if (root == nullptr) 
		return nullptr;
	if (root->data == x) {
		//if it's a leaf
		if (root->left == nullptr && root->right == nullptr) {
			root = nullptr;
			return nullptr;
		}
		//if node has only one child:
		if (root->left == nullptr) {
			node *n = root->right;
			root = nullptr;
			return n;
		}
		if (root->right == nullptr) {
			node *n = root->left;
			root = nullptr;
			return n;
		}
		//if node has 2 children propagate right-most node at that position and delete node:
		node *curr = root;
		node *it = curr->right;
		node *prevIt = nullptr;
		while (it->left != nullptr) {
			prevIt = it;
			it = it->left;
		}
		curr->data = it->data;
		if (prevIt != nullptr)
			prevIt->left = nullptr;

		node *nr = new node;
		nr->data = curr->data;
		nr->left = root->left;
		nr->right = root->right;

		return nr;
	} 
	if (root->data < x)
		root->right = deleteNodeRecursive(root->right, x);
	if (root->data > x)
		root->left = deleteNodeRecursive(root->left, x);
	return root;	
}


void inorder(node* root) {
	if (root == nullptr)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

node *deleteNode(node *root, int x) {
	node *curr = root;
	node *prev = nullptr;
	while (curr->data != x) {
		prev = curr;
		if (curr->data < x)
			curr = curr->right;
		else if (curr->data > x)
			curr = curr->left;
	}
	//if it's a leaf:
	if (curr->left == nullptr && curr->right == nullptr) {
		//cout << "leaf " << curr->data << endl;
		if (curr->data < prev->data)
			prev->left = nullptr;
		else
			prev->right = nullptr;
		return root;
	}
	//if node has only one child:
	if (curr->right == nullptr) {
		prev->right = curr->left;
		curr = nullptr;
		return root;
	}
	
	if (curr->left == nullptr) {
		prev->left = curr->right;
		curr = nullptr;
		return root;
	}
	
	//if node has 2 children propagate right-most node at that position and delete node:
	node *it = curr->right;
	node *prevIt = nullptr;
	while (it->left != nullptr) {
		prevIt = it;
		it = it->left;
	}
	curr->data = it->data;
	if (prevIt != nullptr)
		prevIt->left = nullptr;
	return root;
}


int main() {
	int nrTests;
	cin >> nrTests;
	for (int i = 0; i < nrTests; i++) {
		int length;
		cin >> length;
		int arr[length];
		for (int j = 0; j < length; j++) {
			cin >> arr[j];
		}
		int keyToDelete;
		cin >> keyToDelete;
		cout << "delete " << keyToDelete << endl;
		sort(arr, arr + length);
		node *root = buildBST(arr, 0, length - 1);
		node *nr = deleteNodeRecursive(root, keyToDelete);
		inorder(root);
		cout << "----------------------------------------" << endl;
	}
}
