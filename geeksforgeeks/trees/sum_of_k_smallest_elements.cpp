#include<iostream>
#include<cmath>
#include<algorithm>
#include <set>
#include<utility>
using namespace std;

struct node {
	int data;
	node *left, *right;
};

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

void inorder(node *root, int &count, int &sum, int k) {
	if (root == nullptr) return;
	inorder(root->left, count, sum, k);
	sum += root->data;
	count++;
	if (count == k) {
		cout << sum << endl;
		return;
	}
	inorder(root->right, count, sum, k);
}

bool distinct(int i, int j) {
	return i != j;
}

//void removeDuplicates1(int sortedArr[], int length) {
//	int j = 1;
//	int i = 0;
//	cout << sortedArr[0] << endl;
//	while (j != length) {
//		if (sortedArr[j] == sortedArr[i]) {
//			int count = 0;
//			while (sortedArr[j] == sortedArr[i]) {
//				j++;
//				count++;
//			}
//			i += count;
//		} else {
//			cout << sortedArr[j] << endl;
//			j++;
//			i++;
//		}
//	}
//}

pair<int*,int> removeDuplicates2(int sortedArr[], int length) {
	set<int> s(sortedArr, sortedArr + length);
	int *arr= new int[s.size()];
	set<int>::iterator it;
	int i = 0;
	for (it = s.begin(); it != s.end(); it++) {
		arr[i] = *it;
		i++;
	}
	return make_pair(arr, s.size());
}

int main() {
	int nrTests;
	cin >> nrTests;
	for (int i = 0; i < nrTests; i++) {
		int n;
		cin >> n;
		int arr[n];
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		sort(arr, arr + n);
		pair<int*, int> newArr = removeDuplicates2(arr, n);
		node *root = buildBST(newArr.first, 0, newArr.second - 1);
		int k;
		cin >> k;
		int count = 0;
		int sum = 0;
		inorder(root, count, sum, k);
	}

}
