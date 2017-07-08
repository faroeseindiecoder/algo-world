#include<iostream>
using namespace std;

//when you pass an array to a function, its address is passed to the 
//function as a pointer ---> length info is lost -> need to provide length as well
int findMissingNumber(int arr1[], int length1, int arr2[]) {
	int x = 0; //identity element
	for (int i = 0; i < length1; i++) {
		x ^= arr1[i];
	}
	for (int i = 0; i < length1 - 1; i++) {
		x ^= arr2[i];
	}
	return x;
}

int main() {
//	int arr1[] = {4, 8, 1, 3, 7};
//	int length1 = sizeof(arr1)/sizeof(arr1[0]);
//	int arr2[] = {7, 4, 3, 1};
//	cout << findMissingNumber(arr1, length1, arr2) << endl;
	int nrTests;
	cin >> nrTests;
	for (int i = 0; i < nrTests; i++) {
		int length1;
		cin >> length1;
		int arr1[length1];
		for (int i = 0; i < length1; i++) {
			cin >> arr1[i];
		}
		int arr2[length1 - 1];
		for (int i = 0; i < length1 - 1; i++) {
			cin >> arr2[i];
		}
		cout << findMissingNumber(arr1, length1, arr2) << endl;
	}
}
