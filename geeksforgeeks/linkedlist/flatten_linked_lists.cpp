#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node *next;
	struct Node *bottom;
};

Node* mergeLinkedLists(Node *root1, Node *root2) {
	if (root1 == nullptr)
		return root2;
	if (root2 == nullptr)
		return root1;

	Node *newLinkedList = new Node;
	Node *head = newLinkedList;
	
	if (root1->data < root2->data) {
		newLinkedList->data = root1->data;
		root1 = root1->bottom;
	} else {
		newLinkedList->data = root2->data;
		root2 = root2->bottom;
	}

	while (root1 != nullptr && root2 != nullptr) {
		if (root1->data < root2->data) {
			newLinkedList->bottom = root1;
			root1 = root1->bottom;
		} else {
			newLinkedList->bottom = root2;
			root2 = root2->bottom;
		}
		newLinkedList = newLinkedList->bottom;
	}
	if (root1 != nullptr) 
		newLinkedList->bottom = root1;
		
	if (root2 != nullptr) 
		newLinkedList->bottom = root2;
		
	return head;
}

void testMergeFunction() {
	Node *root11 = new Node;
	Node *root12 = new Node;
	root11->data = 1;
	root11->bottom = root12;
	root11->next = nullptr;
	root12->data = 5;
	root12->next = nullptr;
	root12->bottom = nullptr;
	
	Node *root21 = new Node;
	Node *root22 = new Node;
	root21->data = 2;
	root21->bottom = root22;
	root21->next = nullptr;
	root22->data = 7;
	root22->next = nullptr;
	root22->bottom = nullptr;
	
	Node *head = mergeLinkedLists(root11, root21);
	while (head != nullptr) {
		cout << head->data << endl;
		head = head->bottom;
	}
}


Node* flatten(Node *root) {
	Node *head = root;
	Node *nextHead = head->next;

	while (nextHead != nullptr) {
		Node *curr = head->bottom;
		if (curr != nullptr) {
			Node *prev = nullptr;
			while (curr != nullptr && curr->data < nextHead->data) {
				head->next = curr;
				head->bottom = nullptr;
				head = curr;
				curr->next = curr->bottom;
				curr->bottom = nullptr;
				prev = curr;
				curr = curr->next;
			}
			if (prev != nullptr) 
				prev->bottom = nullptr;
				
			head->bottom = nullptr;
			head->next = nextHead;
			Node *newLinkedList = mergeLinkedLists(curr, nextHead->bottom);
			nextHead->bottom = newLinkedList;
		}
		head = nextHead;
		nextHead = nextHead->next;
		if (nextHead == nullptr) {
			Node *iter = head;
			while (iter != nullptr) {
				iter->next = iter->bottom;
				iter->bottom = nullptr;
				iter = iter->next;
			}
		}
	}
	
	return root;
}

void printLinkedList(Node *root) {
	Node *head = root;
	while (head != nullptr) {
		while (root != nullptr) {
			cout << root->data << endl;
			root = root->bottom;
		}
		head = head->next;
		root = head;
	}
}

int main() {

	int nrTests, nrHeadNodes;
	cin >> nrTests;
	
	for (int i = 0; i < nrTests; i++) {
		cin >> nrHeadNodes;
		int headNodes[nrHeadNodes];
		for (int i = 0; i < nrHeadNodes; i++) {
			cin >> headNodes[i];
		}

		Node *root = new Node;
		Node *head = new Node;
		for (int i = 0; i < nrHeadNodes; i++) {
			int nrElemsLinkedList = headNodes[i];
			Node *curr = new Node;
			cin >> curr->data;
			if (i == 0) {
				head = curr;
				root = head;
			} else {
				head->next = curr;
				head = head->next;
			}
			for (int j = 1; j < nrElemsLinkedList; j++) {
				Node *n = new Node;
				cin >> n->data;
				n->next = nullptr;
				n->bottom = nullptr;
				cout << n->data << "*" << endl;
				curr->bottom = n;
				curr->next = nullptr;
				curr = curr->bottom;
			}
			curr->bottom = nullptr;
		}
		
		cout << "Original list " << endl;
		printLinkedList(root);
		cout << "Flattened " << endl;
		Node *flattened = flatten(root);
		printLinkedList(flattened);
	}
}
