#include<iostream>
#include<cassert>
using namespace std;

#define md 1000000007

//at most 2 adjacent posts can have the same color
long getNumPossibleColorings(int numPosts, int numColors) {
	long diff[numPosts + 1] = {0};
	long same[numPosts + 1] = {0};

	diff[1] = numColors;
	same[1] = 0;
	
	diff[2] = numColors * (numColors - 1);
	same[2] = numColors;
	
	for (int i = 3; i <= numPosts; i++) {
		diff[i] = (numColors - 1) * (diff[i - 1] + diff[i - 2]) % md;
		same[i] = diff[i - 1];
	}
	return (diff[numPosts] + same[numPosts]) % md;
}

int main() {
	cout << "Test cases:" << endl;
	assert(getNumPossibleColorings(15, 2) == 1974);
	assert(getNumPossibleColorings(3, 2) == 6);
	assert(getNumPossibleColorings(2, 4) == 16);
	assert(getNumPossibleColorings(92778, 16) == 373113948);
	cout << "All tests completed." << endl;
}

