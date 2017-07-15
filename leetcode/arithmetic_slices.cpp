#include<iostream>
#include<vector>
using namespace std;

int getNumArithmeticSlices(int lengthMaxArithmeticSlice) {
	int numArithmeticSlices = 0;
	int i = 0;
	while (lengthMaxArithmeticSlice - i >= 3) {
		numArithmeticSlices += 1 + i;
		i++;
	}
	return numArithmeticSlices;
}

int numberOfArithmeticSlices(vector<int>& A) {
	int numArithmeticSlices = 0;
	if (A.size() <= 2) {
		return numArithmeticSlices;
	}
	int currRatio = A[1] - A[0];
	int lengthMaxArithmeticSlice = 2;
	for (int i = 2; i < A.size(); i++) {
		if (A[i] - A[i-1] == currRatio) {
			while (i < A.size() && A[i] - A[i-1] == currRatio) {
				lengthMaxArithmeticSlice++;
				i++;
			} 
		}
		if (lengthMaxArithmeticSlice >= 3) {
			numArithmeticSlices += getNumArithmeticSlices(lengthMaxArithmeticSlice);
			lengthMaxArithmeticSlice = 2;
		} 
		currRatio = A[i] - A[i-1];
	}
	return numArithmeticSlices;
}

int main() {
	vector<int> A = {1, 2, 3, 4, -5, 1, 2, 3};
//	A = {1, 2, 3};
	cout << numberOfArithmeticSlices(A) << endl;
}
