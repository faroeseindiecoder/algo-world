#include<iostream>
#include<cmath>
#include<algorithm>
#include<climits>
using namespace std;

struct node {
	int data;
	node *left, *right;
};

node* inOrderSuccessor(node *root, node *x) {
	if (root == nullptr) return nullptr;
	if (x->right != nullptr) {
		node *it = x->right;
		while (it->left != nullptr) {
			it = it->left;
		}
		return it;
	}
	
	node *successor = nullptr;
	node *curr = root;
	while (curr != x) {
		if (curr->data > x->data) {
			successor = curr;
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
	return successor;
}

int main() {
//	int nrTests;
//	cin >> nrTests;
//	for (int i = 0; i < nrTests; i++) {
//		int n; 
//		cin >> n;
//		int arr[n];
//		for (int j = 0; j < n; j++) {
//			cin >> arr[j];
//		}
//		node *root = buildBST(arr, 0, n-1);
//	}
	node *a1 = new node;
	node *a2 = new node;
	node *a3 = new node;
	node *a4 = new node;
	node *a5 = new node;
	node *a6 = new node;
	node *a7 = new node;
	node *a8 = new node;
	node *a9 = new node;
	node *a10 = new node;
	node *a11 = new node;
	node *a12 = new node;
	
	a1->data = 12;
	a1->left = a2;
	a1->right = a3;
	a2->data = 8;
	a3->data = 20;
	a2->left = a4;
	a2->right = a5;
	a4->data = 4;
	a5->data = 10;
	a4->left = nullptr;
	a4->right = a8;
	a5->left = a9;
	a5->right = a10;
	a3->left = a6;
	a3->right = a7;
	a6->data = 14;
	a7->data = 22;
	a6->left = a11;
	a6->right = a12;
	a7->left = nullptr;
	a7->right = nullptr;
	a8->data = 5;
	a8->right = nullptr;
	a8->left = nullptr;
	a9->data = 9;
	a9->left = nullptr;
	a9->right = nullptr;
	a10->data = 11;
	a10->left = nullptr;
	a10->right = nullptr;
	a11->data = 13;
	a11->left = nullptr;
	a11->right = nullptr;
	a12->data = 15;
	a12->left = nullptr;
	a12->right = nullptr;
	node *successor = inOrderSuccessor(a1, a2);
	cout << successor->data << endl;	
	successor = inOrderSuccessor(a1, a5);
	cout << successor->data << endl;
	successor = inOrderSuccessor(a1, a4);
	cout << successor->data << endl;
	successor = inOrderSuccessor(a1, a6);
	cout << successor->data << endl;
	successor = inOrderSuccessor(a1, a3);
	cout << successor->data << endl;
	successor = inOrderSuccessor(a1, a7);
	successor = inOrderSuccessor(a1, a1);
	cout << successor->data << endl;
	successor = inOrderSuccessor(a1, a12);
	cout << successor->data << endl;	
}
