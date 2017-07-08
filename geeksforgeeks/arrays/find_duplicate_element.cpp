#include<iostream>
#include<vector>
using namespace std;

//given n numbers ranging from 0 to n-2 find the duplicate element
void findDuplicateElement(vector<int> &v) {
	//start 2 pointers (slow and fast) from start of the vector
	int slow = v.size() - 1;
	int fast = v.size() - 1;
	//move the two pointers until they meet
	while (1) {
		slow = v[slow];
		fast = v[v[fast]];
		if (slow == fast) break;
	}
	//slow and fast are now at a common element in the cycle
	//to find start element of the cycle move slow to the beginning 
	//and have both pointers move one position at a time
	slow = v.size() - 1;
	while (1) {
		slow = v[slow];
		fast = v[fast];
		if (slow == fast) {
			cout << "Cycle started at elem: " << slow << endl;
			break;
		}
	}
}

int main() {
	vector<int> v1 = {1, 2, 3, 0, 4, 2};
	findDuplicateElement(v1);
	vector<int> v2 = {1, 5, 1, 2, 3, 4, 0};
	findDuplicateElement(v2);
	vector<int> v3 = {1, 0, 1, 2, 3, 4};
	findDuplicateElement(v3);

}
