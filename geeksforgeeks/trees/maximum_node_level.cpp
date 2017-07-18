#include<iostream>
#include<queue>
#include<functional>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

int getMaxNodeLevel(node *root) {
	queue<node*> q;
	q.push(root);
	pair<int, int> levelMaxNumNodes = make_pair(0, 1);
	int currLevel = 0;
	while(1) {
		int nodesCurrentLevel = q.size();
		if (nodesCurrentLevel > levelMaxNumNodes.second)
			levelMaxNumNodes = make_pair(currLevel, nodesCurrentLevel);
		if (nodesCurrentLevel == 0)
			break;
		while (nodesCurrentLevel > 0) {
			node *curr = q.front();
			q.pop();
			if (curr->left != nullptr)
				q.push(curr->left);
			if (curr->right != nullptr)
				q.push(curr->right);
			nodesCurrentLevel--;
		}
		currLevel++;
	}
	return levelMaxNumNodes.first;
}

int main() {
	node *a1 = new node;
	node *a2 = new node;
	node *a3 = new node;
	node *a4 = new node;
	node *a5 = new node;
	node *a6 = new node;
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
	cout << getMaxNodeLevel(a1) << endl;
}
