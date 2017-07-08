#include<iostream>
#include<vector>
using namespace std;

//find duplicates in O(n) runtime and O(1) extra space
//n integers between 1 and n - 1 inclusive
//handle 0 by adding 1 to each element in the vector
//note: at least one duplicate exists due to the pigeonhole principle
void findDuplicates(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		int currElem = v[i];
		//make element at index currElem negative if it's not already
		if (v[abs(currElem)] > 0) v[abs(currElem)] = -v[abs(currElem)];
		else {
			//already seen => duplicate
			cout << currElem << " is a duplicate" << endl;
		}
	}
}


int main() {
	vector<int> v = {1, 4, 2, 1, 5, 2, 1, 3};
	findDuplicates(v);

}
