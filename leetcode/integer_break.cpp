#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

int integerBreak(int n) {
	vector<int> product(n + 1);
	if (n == 2 || n == 3) {
		return n - 1;
	}
	for (int i = 1; i <= n; i++) {
		product[i] = 1;
	}
	product[2] = 2;
	product[3] = 3;
	for (int i = 4; i <= n; i++) {
		for (int j = 1; j <= i/2; j++) {
			int currentProduct = product[j] * product[i - j];
			if (currentProduct > product[i]) {
				product[i] = currentProduct;
			}
		}
	}
	return product[n];
}

int main() {
	assert(integerBreak(2) == 1);
	assert(integerBreak(10) == 36);
}
