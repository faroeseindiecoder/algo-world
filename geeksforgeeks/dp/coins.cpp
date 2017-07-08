#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int findMinCoinNumber(vector<int> &coinValues, int sum) {
	vector<int> min(sum+1);
	for (int i = 0; i <= sum; i++) {
		min[i] = INT_MAX;
	}
	//we need 0 coins for sum = 0;
	min[0] = 0;
	for (int i = 1; i <= sum; i++) {
		//look at each coin
		for (int j = 0; j < coinValues.size(); j++) {
			//if its value doesn't surpass the sum we are currently computing
			//we add one (coin) to the previously found optimal solution for sum - coin 
			//if we get a value smaller than the previous optimal value 
			//for min[i], we update min[i] with the optimal value we found
			if (coinValues[j] <= i && min[i - coinValues[j]] + 1 < min[i]) {
				min[i] = min[i - coinValues[j]] + 1;
			}
		}
	}
	return min[sum];
}

int main() {
	vector<int> coinValues = {1, 3, 5};
	for (int i = 0; i <= 11; i++) {
		cout << "Min for sum = " << i << " : " << findMinCoinNumber(coinValues, i) << endl;
	}
}
