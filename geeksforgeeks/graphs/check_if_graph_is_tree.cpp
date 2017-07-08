#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

struct node {
	int data; 
	vector<node*> neighbors;
};

struct graph {
	vector<node> vertices;
};

bool isGraphConnected(node *n0, graph &g) {
	//dfs
	stack<node*> s;
	s.push(n0);
	unordered_map<node*, bool> visited;
	int connectedNodesCount = 0;
	while (!s.empty()) {
		node *t = s.top();
		s.pop();
		vector<node*> neighbors = t->neighbors;
		if (!visited[t]) {
			for (int i = 0; i < neighbors.size(); i++) {
				s.push(neighbors[i]);
			}
			visited[t] = true;
			connectedNodesCount++;
		}
	}
	if (connectedNodesCount == g.vertices.size())  {
		return true;
	}
	return false;
}

bool graphContainsCycles(node *n0) {
	//dfs
	queue<node*> s;
	s.push(n0);
	unordered_map<node*, bool> visited;
	unordered_map<node*, node*> childParentMap;
	node *rootParent = new node;
	rootParent->data = -1;
	childParentMap[n0] = rootParent;
	while (!s.empty()) {
		node *t = s.front();
		s.pop();
		vector<node*> neighbors = t->neighbors;	
		//for every visited node v, if there is an already visited node u adjacent to v 
		//which is not a parent of v => cycle detected
		if (visited[t]) {
			cout << "Already visited " << t-> data << endl;
			for (int i = 0; i < neighbors.size(); i++) {
				node *currNeighbor = neighbors[i];
				if (visited[currNeighbor] && childParentMap[currNeighbor] != t) {
					cout << "Neighbor: " << currNeighbor->data << endl;
					return true;
				}
			}
		} else {
			for (int i = 0; i < neighbors.size(); i++) {
				s.push(neighbors[i]);
				childParentMap[neighbors[i]] = t ;
			}
			visited[t] = true;
		}
	}
	return false;
}

bool isGraphTree(node *n0, graph &g) {
	cout << "Connected " << isGraphConnected(n0, g) << endl;
	cout << "Has cycles " << graphContainsCycles(n0) << endl;
	return (isGraphConnected(n0, g) && !(graphContainsCycles(n0)));
}


void test1() {
	node n0, n1, n2, n3, n4;
	n0.data = 0;
	n1.data = 1;
	n2.data = 2;
	n3.data = 3;
	n4.data = 4;
	n0.neighbors = {&n1, &n2, &n3};
	n1.neighbors = {&n0, &n2};
	n2.neighbors = {&n0, &n1};
	n3.neighbors = {&n0, &n4};
	n4.neighbors = {&n3};
	
	graph g;
	g.vertices.push_back(n0);
	g.vertices.push_back(n1);
	g.vertices.push_back(n2);
	g.vertices.push_back(n3);
	g.vertices.push_back(n4);

	cout << isGraphTree(&n0, g) << endl;	
}

void test2() {
	node n0, n1, n2;
	n0.data = 1;
	n1.data = 2;
	n2.data = 3;
	n0.neighbors = {&n1, &n2};
	n1.neighbors = {&n0, &n2};
	n2.neighbors = {&n0, &n1};
	
	graph g;
	g.vertices.push_back(n0);
	g.vertices.push_back(n1);
	g.vertices.push_back(n2);
	
	cout << isGraphTree(&n0, g) << endl;	
}

void test3() {
	node n0, n1, n2, n3;
	n0.data = 1;
	n1.data = 2;
	n2.data = 3;
	n3.data = 4;
	n0.neighbors = {&n1, &n2};
	n1.neighbors = {&n0, &n2};
	n2.neighbors = {&n0, &n1};
	n3.neighbors = {};
	
	graph g;
	g.vertices.push_back(n0);
	g.vertices.push_back(n1);
	g.vertices.push_back(n2);
	g.vertices.push_back(n3);
	
	cout << isGraphTree(&n0, g) << endl;	
}

void test4() {
	node n0, n1, n2, n3, n4;
	n0.data = 0;
	n1.data = 1;
	n2.data = 2;
	n3.data = 3;
	n4.data = 4;
	n0.neighbors = {&n1, &n2, &n3};
	n1.neighbors = {&n0};
	n2.neighbors = {&n0};
	n3.neighbors = {&n0, &n4};
	n4.neighbors = {&n3};
	
	graph g;
	g.vertices.push_back(n0);
	g.vertices.push_back(n1);
	g.vertices.push_back(n2);
	g.vertices.push_back(n3);
	g.vertices.push_back(n4);

	cout << isGraphTree(&n0, g) << endl;	

}

void test5() {
	node n0, n1, n2, n3, n4, n5;
	n0.data = 0;
	n1.data = 1;
	n2.data = 2;
	n3.data = 3;
	n4.data = 4;
	n5.data = 5;
	n0.neighbors = {&n1, &n2, &n3};
	n1.neighbors = {&n0};
	n2.neighbors = {&n0};
	n3.neighbors = {&n0, &n4};
	n4.neighbors = {&n3};
	n5.neighbors = {};
	
	graph g;
	g.vertices.push_back(n0);
	g.vertices.push_back(n1);
	g.vertices.push_back(n2);
	g.vertices.push_back(n3);
	g.vertices.push_back(n4);
	g.vertices.push_back(n5);
	
	cout << isGraphTree(&n0, g) << endl;	

}

int main() {
	cout << "Test 1" << endl;
	test1();
	cout << "Test 2" << endl;
	test2();
	cout << "Test 3" << endl;
	test3();
	cout << "Test 4" << endl;
	test4();
	cout << "Test 5" << endl;
	test5();
}
