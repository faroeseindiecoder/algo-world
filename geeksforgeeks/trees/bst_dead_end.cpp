#include<iostream>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<set>
#include<utility>
#include<queue>
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

node* getSuccessor(node *root, node *x) {
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
		} else {
			curr = curr->right;
		}
	}
	return successor;
}

unordered_map<node*, node*> getSuccessorMap(node *root) {
	stack<node*> s;
	s.push(root);
	unordered_map<node*, bool> visited;
	unordered_map<node*, node*> succMap;
	while (!s.empty()) {
		node *t = s.top();
//		cout << t->data << endl;
		s.pop();
		if (!visited[t]) {
			node* succ = getSuccessor(root, t);
			succMap[t] = succ;
			if (t->left != nullptr) 
				s.push(t->left);
			if (t->right != nullptr) 
				s.push(t->right);
			visited[t] = true;
		}
	}
	return succMap;
}

void bfs(node *root) {
	queue<node*> q;
	q.push(root);
	unordered_map<node*, bool> v;
	while (!q.empty()) {
		node *f = q.front();
		cout << f->data << "*";
		q.pop();
		if (!v[f]) {
			if (f->left != nullptr)
				q.push(f->left);
			if (f->right != nullptr)
				q.push(f->right);
			v[f] = true;
		}
	}
}

int nodeIsDeadEnd(node *root, node *t, unordered_map<node*, node*> &succMap) {
	if ((t->left != nullptr && t->right == nullptr)|| 
		(t->left == nullptr && t->right != nullptr))
		return 0;
	node *succ = getSuccessor(root, t);
	if (succ == nullptr) 
		return 0;
	//find predecessor of node t:
	node *pred = nullptr;
	for (auto &pair : succMap) {
		if (pair.second == t)
			pred = pair.first;
	}
	
	if (pred == nullptr) {
		if (t->data != 1)
			return 0;
		if (t->data == 1 && succ->data != 2)
			return 0;
		if (t->data == 1 && succ->data == 2)
			return 1;
	}
	if (succ->data - pred->data == 2)  {
		return 1;
	}
	return 0;

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


int hasDeadEnd(node *root) {
	//dfs to iterate through the nodes
	stack<node*> s;
	s.push(root);
	unordered_map<node*, bool> visited;
	unordered_map<node*, node*> succMap = getSuccessorMap(root);

	while (!s.empty()) {
		node *t = s.top();
		s.pop();
		if (nodeIsDeadEnd(root, t, succMap)) 
			return 1;
		if (!visited[t]) {
			if (t->left != nullptr) 
				s.push(t->left);
			if (t->right != nullptr) 
				s.push(t->right);
			visited[t] = true;
		}
	}
	return 0;
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
		//node *root = buildBST(arr, 0, n - 1);
		pair<int*, int> newArr = removeDuplicates2(arr, n);
		node *root = buildBST(newArr.first, 0, newArr.second - 1);
		cout << hasDeadEnd(root) << endl;
	}
}
