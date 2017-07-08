#include<iostream>
#include<climits>
#include<utility>
#include<algorithm>
#include<cassert>
using namespace std;

//O(n^6)
int maxSumRectangle(int **matrix, int numRows, int numCols) {
	int maxSum = INT_MIN;
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			for (int k = i; k < numRows; k++) {
				for (int l = j; l < numCols; l++) {
					int currSum = 0;
					for (int m = i; m <= k; m++) {
						for (int n = j; n <= l; n++) {	
							currSum += matrix[m][n];
						}
					}
					if (currSum > maxSum) {
						maxSum = currSum;
					}
				
				}
			}
		}
	}
	return maxSum;
}

//O(n^3)
int maxSumContiguousSubarray(int arr[], int n) {
	int maxSum = 0;
	bool hasNegativeElems = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			hasNegativeElems = true;
			break;
		}
		maxSum += arr[i];
	}
	if (!hasNegativeElems)
		return maxSum;

	maxSum = INT_MIN;
	int subarraySize = 1;
	while (subarraySize <= n) {
		for (int i = 0; i < n; i++) {
			if (i + subarraySize - 1 < n) {
				int currSum = 0;
				for (int j = i; j < i + subarraySize; j++) {
					currSum += arr[j];
				}
				if (currSum > maxSum) {
					maxSum = currSum;
				}			
			}			
		}
		subarraySize++;
	}
	return maxSum;
}

//Kadane's algorithm: O(n)
int maxSumContiguousSubarrayOptimized(int arr[], int n) {
	bool hasPositiveElems = false;
	int maxElem = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			hasPositiveElems = true;
			break;
		}
		if (arr[i] > maxElem)
			maxElem = arr[i];
	}
	if (!hasPositiveElems)
		return maxElem;
	
	int maxSum = INT_MIN;
	int maxSumUpToCurrPos = 0;
	for (int i = 0; i < n; i++) {
		maxSumUpToCurrPos += arr[i];
		if (maxSumUpToCurrPos < 0) {
			maxSumUpToCurrPos = 0;
		} 
		if (maxSumUpToCurrPos > maxSum) {
			maxSum = maxSumUpToCurrPos;
		}
	}
	return maxSum;

}

//O(n^3)
int maxSumRectangleOptimized(int **matrix, int numRows, int numCols) {
	int maxSum = 0;
	for (int leftCol = 0; leftCol < numCols; leftCol++) {
		int temp[numRows] = {0};
		for (int rightCol = leftCol; rightCol < numCols; rightCol++) {
			for (int i = 0; i < numRows; i++) {
				temp[i] += matrix[i][rightCol];
			}
			int currSum = maxSumContiguousSubarrayOptimized(temp, numRows);
			if (currSum > maxSum)
				maxSum = currSum;
		}
	}
	return maxSum;
}


int **initMatrix(int numRows, int numCols) {
	int **matrix = new int*[numRows];
	for (int i = 0; i < numRows; i++)
		matrix[i] = new int[numCols];
	return matrix;
}

void maxSumContiguousSubarrayOptimizedTest1() {
	int numRows = 4, numCols = 5;
	int **matrix = initMatrix(numRows, numCols);
	int testMatrix1[4][5] = {{1, 2, -1, -4, -20}, {-8, -3, 4, 2, 1}, {3, 8, 10, 1, 3}, {-4, -1, 1, 7, -6}};
	copy(&testMatrix1[0], &testMatrix1[0] + numCols, &matrix[0]);
	assert(maxSumRectangleOptimized(matrix, numRows, numCols) == 29);
}

void maxSumContiguousSubarrayOptimizedTest2() {
	int numRows = 4, numCols = 4;
	int **matrix = initMatrix(numRows, numCols);
	int testMatrix[4][4] = {{0, -2, -7, 0}, {9, 2, -6, 2}, {-4, 1, -4, 1}, {-1, 8, 0, -2}};
	copy(&testMatrix[0], &testMatrix[0] + numCols, &matrix[0]);
	assert(maxSumRectangleOptimized(matrix, numRows, numCols) == 15);
}

int main() {
	maxSumContiguousSubarrayOptimizedTest1();
	maxSumContiguousSubarrayOptimizedTest2();
	
	int arr1[12] = {1, 2, 3, 4, 5, 50, -58, 7, 8, 9, 10, 1};
	cout << maxSumContiguousSubarrayOptimized(arr1, sizeof(arr1)/sizeof(arr1[0])) << endl;


	int arr2[12] = {1, 2, 3, -1, 5, 5, -5, 7, -4, 9, 10, 1};
	cout << maxSumContiguousSubarrayOptimized(arr2, sizeof(arr2)/sizeof(arr2[0])) << endl;
	
	int arr3[5] = {-2, -4, -8, -56, -9};
	assert(maxSumContiguousSubarrayOptimized(arr3, 5) == -2);
}


