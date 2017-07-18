#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

void leftView(Node *root) {
	if (root == nullptr) {
		return;
	}
	queue<Node*> q;
	q.push(root);
	bool printNextNode = true;
	while(1) {
		int nodesCurrentLevel = q.size();
		if (nodesCurrentLevel == 0) 
			break;
		while (nodesCurrentLevel > 0) {
			Node *n = q.front();
			if (printNextNode) {
				cout << n->data << " ";
			}
			q.pop();
			if (n->left != nullptr)
				q.push(n->left);
			if (n->right != nullptr)
				q.push(n->right);
			nodesCurrentLevel--;
			if (nodesCurrentLevel == 0) {
				printNextNode = true;
			} else {
				printNextNode = false;
			}
		}
	}
}

int main() {
	Node *a1 = new Node;
	Node *a2 = new Node;
	Node *a3 = new Node;
	Node *a4 = new Node;
	Node *a5 = new Node;
	Node *a6 = new Node;
	a1->data = 2;
	a1->left = a2;
	a1->right = a3;
	a2->data = 4;
	a3->data = 5;
	a2->left = a4;
	a2->right = a5;
	a4->data = 1;
	a5->data = 10;
	a3->left = a6;
	a6->data = 6;
	leftView(a1);
}
