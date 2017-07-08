#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

void sortStack1(stack<int> &s) {
	priority_queue<int> pq;
	while (!s.empty()) {
		pq.push(s.top());
		s.pop();
	}
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

bool comp(int a, int b) {
	return a > b;
}

void sortStack2(stack<int> &s) {
	vector<int> v;
	while (!s.empty()) {
		v.push_back(s.top());
		s.pop();
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

stack<int> sortStack3(stack<int> &s) {
	if (s.size() == 1) {
		return s;
	} else {
		int topElem = s.top();
		s.pop();
		stack<int> rs = sortStack3(s);
		stack<int> ns;
		while (!rs.empty() && rs.top() > topElem) {
			ns.push(rs.top());
			rs.pop();
		}
		ns.push(topElem);
		while (!rs.empty()) {
			ns.push(rs.top());
			rs.pop();
		}
		while (!ns.empty()) {
			rs.push(ns.top());
			ns.pop();
		}
		return rs;
	}
}

int main() {
	stack<int> s;
	s.push(2);
	s.push(1);
	s.push(5);
	s.push(4);
	s.push(3);
	stack<int> ns = sortStack3(s);
	while (!ns.empty()) {
		cout << ns.top() << endl;
		ns.pop();
	}
}
