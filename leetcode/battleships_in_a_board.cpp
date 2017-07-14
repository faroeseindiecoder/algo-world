#include<iostream>
#include<vector>
using namespace std;

int countBattleships(vector<vector<char>>& board) {
	int battleShipsCount = 0;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 'X' && (i == 0 || board[i-1][j] != 'X') && (j == 0 || board[i][j-1] != 'X')) {
				battleShipsCount++;
			}
		}
	}
	return battleShipsCount;
}

int main() {
	vector<vector<char>> board = {{'X', '.', '.', 'X'}, {'.','X','.','X'}, {'X', '.', '.', 'X'}};
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << countBattleships(board) << endl;

}
