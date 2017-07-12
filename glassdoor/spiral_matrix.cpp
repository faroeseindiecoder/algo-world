#include<iostream>
using namespace std;

void printMatrix(int **matrix, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void fillOuterFrame(int **matrix, int startCol, int endCol, int curr) {
	int startRow = startCol;
	int endRow = endCol;
	while (startRow <= endRow) {
		for (int j = startCol; j <= endCol - 1; j++) 
			matrix[startRow][j] = curr++;

		for (int i = startRow; i <= endRow - 1; i++)
			matrix[i][endCol] = curr++;

		for (int j = endCol; j >= startCol + 1; j--)
			matrix[endRow][j] = curr++;
		
		for (int i = endRow; i >= startRow + 1; i--)
			matrix[i][startCol] = curr++;
		startCol++;
		endCol--;
		startRow++;
		endRow--;
		if (startRow == endRow) {
			matrix[startRow][startCol] = curr++;
		}
	}
	
}

int main() {

	int N = 7;
	int **matrix = new int*[N];
	for (int i = 0; i < N; i++)
		matrix[i] = new int[N];
		
	fillOuterFrame(matrix, 0, N-1, 1);
	printMatrix(matrix, N);

}
