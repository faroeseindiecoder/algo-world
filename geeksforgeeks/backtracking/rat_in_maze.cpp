#include<iostream>
using namespace std;

#define N 4

//note: 0 means dead end
//allowed moves: forward & down

bool isSafe(int m[N][N], int i, int j) {
	return m[i][j] == 1;
}

bool solveMaze(int m[N][N], int i, int j, int sol[N][N]) {
	if (i >= N && j >= N)
		return true;
		
	//idea: try going right or down, if that turns out to be wrong, backtrack and delete rat position
	if (isSafe(m, i + 1, j)) {
		//one step down:
		sol[i + 1][j] = 1;
		if (solveMaze(m, i + 1, j, sol)) {
			return true;
		}
		sol[i + 1][j] = 0;
	}
	if (isSafe(m, i, j + 1)) {
		sol[i][j + 1] = 1;
		//one step right
		if (solveMaze(m, i, j + 1, sol)) {
			return true;
		}
		sol[i][j + 1] = 0;
	}
	//couldn't solve the maze from this position
	return false;
}

void test1() {
	cout << "Input matrix:" << endl;
	int m[N][N] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	int sol[N][N] = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	if (solveMaze(m, 0, 0, sol)) {
		cout << "Solution matrix:" << endl;
		for(int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}	
	} else {
		cout << "Unreachable destination." << endl;
	}
}

int main() {
	test1();
}


