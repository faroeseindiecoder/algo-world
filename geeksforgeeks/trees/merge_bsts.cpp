#include<iostream>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;

struct node {
	int data;
	node *right, *left;
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

void inorder(node *root, queue<int> &q) {
	if (root == nullptr) return;
	inorder(root->left, q);
	q.push(root->data);
	inorder(root->right, q);
}

void merge(node *root1, node *root2) {
	queue<int> q1;
	inorder(root1, q1);
	queue<int> q2;
	inorder(root2, q2);
	while (!q1.empty() && !q2.empty()) {
		if (q1.front() < q2.front()) {
			cout << q1.front() << " ";
			q1.pop();
		} else {
			cout << q2.front() << " ";
			q2.pop();
		}
	}
	while (!q1.empty()) {
		cout << q1.front() << " ";
		q1.pop();
	}
	while (!q2.empty()) {
		cout << q2.front() << " ";
		q2.pop();
	}
	cout << endl;
}


int main() {
	int nrTests;
	cin >> nrTests;
	for (int i = 0; i < nrTests; i++) {
		int length1, length2;
		cin >> length1 >> length2;
		int arr1[length1], arr2[length2];
		for (int i = 0; i < length1; i++) {
			cin >> arr1[i];
		}
		sort(arr1, arr1 + length1);
		node *root1 = buildBST(arr1, 0, length1 - 1);
		for (int i = 0; i < length2; i++) {
			cin >> arr2[i];
		}
		sort(arr2, arr2 + length2);
		node *root2 = buildBST(arr2, 0, length2 - 1);
		merge(root1, root2);
	}

}
