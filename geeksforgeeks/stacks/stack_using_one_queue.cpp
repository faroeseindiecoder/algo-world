#include<iostream>
#include<queue>
using namespace std;

class mystack {
	int size = 0;
	queue<int> q;
	int top;

	public:
	//push
	 void pushToStack(int x) {
		q.push(x);
		top = x;
		size++;
	}
	//pop
	void popFromStack() {
		if (!q.empty()) {
			for (int i = 0; i < size - 1; i++) {
				q.push(q.front());
				q.pop();
			}
			q.pop();
			size--;
			top = q.back();
		}
	}
	//top
	void showTop() {
		cout << "Top is: " << top << endl;
	} 
	//empty
	bool isEmpty() {
		return size == 0;
	}
	
	void print() {
		if (!q.empty()) {
			for (int i = 0; i < size; i++) {
				int top = q.front();
				cout << top << " ";
				q.pop();
				q.push(top);
			}
			cout << endl;
		} else {
			cout << "Empty stack" << endl;
		}
	}
	
	void showSize() {
		cout << "Size: " << size << endl;
	}
};

void test() {
	mystack s;
	s.pushToStack(1);
	s.pushToStack(5);
	s.pushToStack(9);
	s.pushToStack(2);
	s.pushToStack(3);
	s.print();
	s.showSize();
	s.showTop();
	s.popFromStack();
	s.showTop();
	s.pushToStack(8);
	s.print();
	s.popFromStack();
	s.popFromStack();
	s.popFromStack();
	s.popFromStack();
	s.popFromStack();
	s.pushToStack(10);
	s.showTop();
	s.print();
	s.showSize();
}


int main() {
	test();
}
