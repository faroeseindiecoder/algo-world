#include<iostream>
using namespace std;

#define N 4

bool isSafe(int m[N][N], int rowIndex, int columnIndex) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (m[i][j] == 1) {
				if (i == rowIndex || j == columnIndex || rowIndex - i == columnIndex - j)
					return false;
			}
		}
	}
	return true;
}

bool solveQueens(int m[N][N], int col) {
	//if all queens are placed
	if (col >= N)
		return true;
	//try placing the queen on all rows for this column:
	for (int i = 0; i < N; i++) {
		if (isSafe(m, i, col)) {
			m[i][col] = 1;
			//curr pos is safe so try placing next queen:
			if (solveQueens(m, col + 1))
				return true;
			//if next queens cannot be placed remove the queen at this position:
			m[i][col] = 0;
		}
	}
	//queen cannot be placed on any row in this column
	return false;
}


int main() {
	//initialize matrix:
	int m[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			m[i][j] = 0;
		}
	}
	
	solveQueens(m, 0);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}
