#include<iostream>
#include<queue>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

node* mirrorBinaryTree(node *root) {
	if (root == nullptr) {
		return nullptr;
	}
	node *leftChild = mirrorBinaryTree(root->left);
	node *rightChild = mirrorBinaryTree(root->right);
	root->left = rightChild;
	root->right = leftChild;
	return root;
}

void levelOrderTraversal(node *root) {
	queue<node*> q;
	q.push(root); 
	
	while(1) {
		int nodesCurrentLevel = q.size(); 
		if (nodesCurrentLevel == 0)
			break;
		while (nodesCurrentLevel > 0) {
			node *n = q.front();
			cout << n->data << " ";
			q.pop();
			if (n->left != nullptr)
				q.push(n->left);
			if (n->right != nullptr)
				q.push(n->right);
			nodesCurrentLevel--;
		}
		cout << endl;
	}
}

int main() {
	node *a1 = new node;
	node *a2 = new node;
	node *a3 = new node;
	node *a4 = new node;
	node *a5 = new node;
	a1->data = 2;
	a1->left = a2;
	a1->right = a3;
	a2->data = 4;
	a3->data = 5;
	a2->left = a4;
	a2->right = a5;
	a4->data = 1;
	a5->data = 10;
	node *r = mirrorBinaryTree(a1);
	levelOrderTraversal(r);
}
