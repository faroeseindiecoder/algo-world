#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int minSquareCuts(int width, int height) {
	static int memo[10000][10000];

	if (width == height) {
		return 1;
	}
	if (memo[width][height])
		return memo[width][height];
	//try to cut somewhere on the width:
	int minCutsWidth = INT_MAX;
	for (int i = 1; i <= width/2; i++) {
		int minW = minSquareCuts(i, height) + minSquareCuts(width - i, height);
		if (minW < minCutsWidth)
			minCutsWidth = minW;
	}
	//try to cut somewhere on the height:
	int minCutsHeight = INT_MAX;
	for (int i = 1; i <= height/2; i++) {
		int minH = minSquareCuts(width, i) + minSquareCuts(width, height - i);
		if (minH < minCutsHeight)
			minCutsHeight = minH;
	}
	memo[width][height] = min(minCutsWidth, minCutsHeight);
	return memo[width][height];

}


int main() {
	int nrTests;
	cin >> nrTests;
	
	for (int i = 0; i < nrTests; i++) {
		int width, height;
		cin >> width >> height;
		cout << minSquareCuts(width, height) << endl;
	}
}
