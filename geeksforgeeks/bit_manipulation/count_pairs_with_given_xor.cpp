#include<iostream>
#include<algorithm>
#include<functional>
#include<unordered_set>
#include<cassert>

using namespace std;

//O(n^2)
int countPairsWithGivenXor1(int arr[], int size, int x) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			int xOr = arr[i] ^ arr[j];
			if (xOr == x) {
				count++;
			}
		}
	}
	return count;
}

bool xOrPresentInArray(int arr[], int size, int x) {
	int start = 0;
	int end = size - 1;
	while (start <= end) {
		int mid = start + (end - start)/2;
		if (arr[mid] == x)
			return true;
		else if (arr[mid] < x)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return false;
}


//O(n log n)
int countPairsWithGivenXor2(int arr[], int size, int x) {
	int count = 0;
	sort(arr, arr + size);
	for (int i = 0; i < size; i++) {
		int xOr = arr[i] ^ x;
		if (xOrPresentInArray(arr, size, xOr) && arr[i] != xOr) {
			count++;
		}
	}
	return count/2;
}


int countPairsWithGivenXor3(int arr[], int size, int x) {
	int count = 0;
	unordered_set<int> s;
	for (int i = 0; i < size; i++) {
		int xOr = arr[i] ^ x;
		if (s.find(xOr) != s.end())
			count++;
		s.insert(arr[i]);
	}
	return count;
}

int main() {

	int arr1[] = {3, 6, 8, 10, 15, 50};
	assert(countPairsWithGivenXor1(arr1, 6, 5) == 2); 
	assert(countPairsWithGivenXor2(arr1, 6, 5) == 2);
	assert(countPairsWithGivenXor3(arr1, 6, 5) == 2);
	
	int arr2[] = {5, 4, 10, 15, 7, 6};
	assert(countPairsWithGivenXor1(arr2, 6, 5) == 1);
	assert(countPairsWithGivenXor2(arr2, 6, 5) == 1);
	assert(countPairsWithGivenXor3(arr2, 6, 5) == 1);
}
