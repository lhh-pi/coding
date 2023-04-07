#include <vector> 
#include <string>

using namespace std;

class Solution {
private:
    bool flag = false;
    bool isValid(vector<vector<char>>& board, int row, int col, char val) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == val) return false;
        }
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == val) return false;
        }
        int r = (row / 3) * 3;
        int c = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[r + i][c + j] == val) return false;
            }
        }
        return true;
    }

    void search(vector<vector<char>>& board, int row, int col) {
        if (row == 9) {
            flag = true;
            return;
        }
        int new_row, new_col;
        if (col == 8) {
            new_row = row + 1;
            new_col = 0;
        }
        else {
            new_row = row;
            new_col = col + 1;
        }

        if (board[row][col] != '.') {
            search(board, new_row, new_col);
            return;
        }
        for (char ch = '1'; ch <= '9'; ch++) {
            if (!isValid(board, row, col, ch)) continue;
            board[row][col] = ch;
            search(board, new_row, new_col);
            if (flag) return;
            board[row][col] = '.';
        }
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        search(board, 0, 0);
    }
};

int main() {
    vector<vector<char>> str = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
    Solution solution;
    solution.solveSudoku(str);
}