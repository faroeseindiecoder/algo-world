#include<iostream>
#include<set>
#include<utility>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;


struct node {
	int data;
	node *left, *right;
};

node *buildBST(int arr[], int start, int end) {
	if (start > end) return nullptr;
	if (start == end) {
		node *leaf = new node;
		leaf->data = arr[start];
		leaf->left = nullptr;
		leaf->right = nullptr;
		return leaf;
	}
	node *root = new node;
	int rootIndex = floor(start + (end - start)/2);
	root->data = arr[rootIndex];
	root->left = buildBST(arr, start, rootIndex - 1);
	root->right = buildBST(arr, rootIndex + 1, end);
	return root;
}

struct nodes {
	set<int> allnodes;
	set<int> leaves;
};

nodes getNodes(node *root) {
	set<int> allnodes;
	set<int> leaves;
	//dfs
	stack<node*>s;
	s.push(root);
	unordered_map<node*,bool> v;
	while (!s.empty()) {
		node *t = s.top();
		s.pop();
		if (t->left == nullptr && t->right == nullptr) {
			leaves.insert(t->data);
		}
		allnodes.insert(t->data);
		if (t->left != nullptr)
			s.push(t->left);
		if (t->right != nullptr)
			s.push(t->right);
		v[t] = true;
	}
	return {allnodes, leaves};
}

bool isDeadEnd(node *root) {
	nodes ns = getNodes(root);
	set<int> allnodes = ns.allnodes;
	allnodes.insert(0);
	set<int> leaves = ns.leaves;
	set<int>::iterator it;
	for (auto &leaf : leaves) {
		//look for predecessor & successor:
		if (allnodes.find(leaf-1) != allnodes.end() && allnodes.find(leaf+1) != allnodes.end()) {
			return true;
		}
	}

	return false;	
}

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
		pair<int*, int> newArr = removeDuplicates2(arr, n);
		sort(newArr.first, newArr.first + newArr.second);
		node *root = buildBST(newArr.first, 0, newArr.second - 1);
		cout << isDeadEnd(root) << endl; 
	}
}


