#include<iostream>
#include<cmath>
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

void inorder(node *root, int &i, int k) {
	if (root == nullptr) return;
	inorder(root->left, i, k);
	if (i == k) cout << root->data << endl;
	i++;
	inorder(root->right, i, k);
}

int main() {
	int arr[] = {4, 8, 10, 12, 14, 20, 22};
	int length = sizeof(arr)/sizeof(arr[0]);
	node *root = buildBST(arr, 0, length - 1);
	int i = 0;
	inorder(root, i, 6);
}
