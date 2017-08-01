#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

//memory limit for large input
int lastRemaining1(int n) {
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	int start = 0;
	int end = n - 1;
	int step = 2;
	while (start < end) {
		for (int i = start; i <= end; i += step) {
			v[i] = 0;
		}
		while (v[end] == 0) {
			end--;
		}
		while (v[start] == 0) {
			start++;
		} 
		step *= 2;
		if (start < end) {
			for (int j = end; j >= start; j -= step ) {
				v[j] = 0;
			}
			while (v[end] == 0) {
				end--;
			}
			while (v[start] == 0) {
				start++;
			}
			step *= 2;
		}
	}
	
	return v[start];
}

//optimized
int lastRemaining2(int n) {
	int start = 1;
	int end = n;
	int step = 2;
	int prevStep = 1;
	while (start < end) {
		start = start + prevStep;
		if (end % step != start % step) {
			end = end - prevStep;
		}
		prevStep = step;
		step *= 2;
		if (start < end) {
			end = end - prevStep;
			if (start % step != end % step) {
				start = start + prevStep;
			}
		}
		prevStep = step;
		step *= 2;
	}
	return start;
}


int main() {
	assert(lastRemaining2(9) == 6);
	assert(lastRemaining2(24) == 14);
}
