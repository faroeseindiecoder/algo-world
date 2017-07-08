#include<iostream>
#include<queue>
#include<cassert>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
	Node *nextRight; //extra space
};

void deleteBinaryTree(Node *root) {
	queue<Node*> q;
	q.push(root);
	
	while (!q.empty()) {
		Node *n = q.front();
		q.pop();
		if (n->left)
			q.push(n->left);
		if (n->right)
			q.push(n->right);
		delete n;
	}
}

void connect(Node *root) {
	if (root == nullptr)
		return;
	
	queue<Node*> q;
	q.push(root);
	Node *prev = nullptr;

	while (1) {
		int numEnqueuedNodesCurrentLevel = q.size();
		if (numEnqueuedNodesCurrentLevel == 0)
			return;
		while (numEnqueuedNodesCurrentLevel > 0) {
			Node *curr = q.front();
			q.pop();
			if (curr->left != nullptr)
				q.push(curr->left);
			if (curr->right != nullptr)
				q.push(curr->right);

			if (prev != nullptr) {
				prev->nextRight = curr;
			}
			
			numEnqueuedNodesCurrentLevel--;
			if (numEnqueuedNodesCurrentLevel > 0) {
				prev = curr;
			}
			else {
				prev = nullptr;
			}
		}
	}
	
}

void test1() {

	Node *root = new Node;
	root->data = 10;
	root->left = new Node;
	root->left->data = 3;
	root->right = new Node;
	root->right->data = 5;
	root->left->left = new Node;
	root->left->left->data = 4;
	root->left->right = new Node;
	root->left->right->data = 1;
	root->right->right = new Node;
	root->right->right->data = 2;
	
	connect(root);
	
	assert(root->nextRight == nullptr);
	assert(root->left->nextRight == root->right);
	assert(root->right->nextRight == nullptr);
	assert(root->left->left->nextRight == root->left->right);
	assert(root->left->right->nextRight == root->right->right);
	assert(root->right->right->nextRight == nullptr);

	cout << "Test 1 completed." << endl;

//	deleteBinaryTree(root);
}

void test2() {

	Node *root = new Node;
	root->data = 10;
	root->left = new Node;
	root->left->data = 5;
	root->right = new Node;
	root->right->data = 20;
	root->left->left = new Node;
	root->left->left->data = 3;
	root->left->right = new Node;
	root->left->right->data = 8;
	root->right->right = new Node;
	root->right->right->data = 25;
	root->left->left->left = new Node;
	root->left->left->left->data = 7;
	root->right->right->right = new Node;
	root->right->right->right->data = 30;

	connect(root);

	assert(root->nextRight == nullptr);
	assert(root->left->nextRight == root->right);
	assert(root->right->nextRight == nullptr);
	assert(root->left->left->nextRight == root->left->right);
	assert(root->left->right->nextRight == root->right->right);
	assert(root->right->right->nextRight == nullptr);
	assert(root->left->left->left->nextRight == root->right->right->right);
	assert(root->right->right->right->nextRight == nullptr);

	cout << "Test 2 completed." << endl;
	
//	deleteBinaryTree(root);
}

void test4() {

	Node *root = new Node;
	root->data = 10;
	root->left = new Node;
	root->left->data = 5;
	root->right = new Node;
	root->right->data = 20;
	root->left->left = new Node;
	root->left->left->data = 3;
	root->right->right = new Node;
	root->right->right->data = 25;
	root->left->left->left = new Node;
	root->left->left->left->data = 7;
	root->right->right->right = new Node;
	root->right->right->right->data = 30;
	
	connect(root);

	assert(root->nextRight == nullptr);
	assert(root->left->nextRight == root->right);
	assert(root->left->left->nextRight == root->right->right);
	assert(root->left->left->left->nextRight == root->right->right->right);

	cout << "Test 4 completed." << endl;
	
//	deleteBinaryTree(root);
}

void test3() {

	Node *root = new Node;
	root->data = 10;
	root->left = new Node;
	root->left->data = 5;
	root->right = new Node;
	root->right->data = 20;
	root->left->left = new Node;
	root->left->left->data = 3;
	root->left->right = new Node;
	root->left->right->data = 8;
	root->right->left = new Node;
	root->right->left->data = 18;
	root->right->right = new Node;
	root->right->right->data = 25;
	root->left->right->left = new Node;
	root->left->right->left->data = 7;
	root->right->right->left = new Node;
	root->right->right->left->data = 23;
	root->right->right->right = new Node;
	root->right->right->right->data = 30;
	root->right->right->left->left = new Node;
	root->right->right->left->left->data = 21;
	root->right->right->left->right = new Node;
	root->right->right->left->right->data = 24;
	
	connect(root);
	
	assert(root->nextRight == nullptr);
	assert(root->left->nextRight == root->right);
	assert(root->right->nextRight == nullptr);
	assert(root->left->left->nextRight == root->left->right);
	assert(root->left->right->nextRight == root->right->left);
	assert(root->right->left->nextRight == root->right->right);
	assert(root->right->right->nextRight == nullptr);
	assert(root->left->right->left->nextRight == root->right->right->left);
	assert(root->right->right->left->nextRight == root->right->right->right);
	assert(root->right->right->right->nextRight == nullptr);
	assert(root->right->right->left->left->nextRight == root->right->right->left->right);
	assert(root->right->right->right->nextRight == nullptr);
	
	cout << "Test 3 completed." << endl;
	
//	deleteBinaryTree(root);
}

int main() {

	test1();
	test2();
	test3();
	test4();
}

