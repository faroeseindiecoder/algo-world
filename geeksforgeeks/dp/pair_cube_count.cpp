#include<iostream>
#include<cmath>
#include<vector>
#include<set>
using namespace std;

int countPairs1(int &n) {
	int count = 0;
	int radOrdThree = pow(n, 1.0/3);
	for (int i = 0; i <= radOrdThree; i++) {
		for (int j = 0; j <= radOrdThree; j++) {
			if (i * i * i + j * j * j == n) {
				count++;
			}
		}
	}
	return count;
}

bool found(vector<int> &v, int &diff) {
	int low = 0;
	int high = v.size() - 1;
	while (low <= high) {
		int mid = (low + high)/2;
		if (v[mid] == diff)
			return true;
		else if (v[mid] < diff) {
			low = mid + 1;
		}
		else if (v[mid] > diff) {
			high = mid - 1;
		}
	}
	return false;
}

int countPairs2(int &n) {
	vector<int> powers;
	int i = 0, sum = 0, count = 0;
	while (sum <= n) {
		powers.push_back(sum);
		i++;
		sum = i * i * i;
	}
	for (int i = 0; i < powers.size(); i++) {
		int diff = n - powers[i];
		if (found(powers, diff))
			count++;
	}
	return count;
}

int countPairs3(int &n) {
	vector<int> powers;
	set<int> seen;
	int i = 0, sum = 0, count = 0;
	while (sum <= n) {
		powers.push_back(sum);
		i++;
		sum = i * i * i;
	}
	
	for (int i = 0; i < powers.size(); i++) {
		if (seen.find(powers[i]) != seen.end())
			break;
		int diff = n - powers[i];
		if (found(powers, diff)) {
			seen.insert(diff);
			count += 2;
		}
	}
	return count;
}

int main() {

	int nrTests;
	cin >> nrTests;

	for (int i = 0; i < nrTests; i++) {
		int n;
		cin >> n;
		cout << countPairs1(n) << endl;
	}
}
