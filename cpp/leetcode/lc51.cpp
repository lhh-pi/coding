#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> chessboard;
    vector<vector<string>> ans;

    bool isValid(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') return false;
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') return false;
        }
        for (int i = row, j = col; i >= 0 && j < chessboard.size(); i--, j++) {
            if (chessboard[i][j] == 'Q') return false;
        }
        return true;
    }

    void search(int n, int row) {
        if (row == n) {
            ans.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (!isValid(row, col)) continue;
            chessboard[row][col] = 'Q';
            search(n, row + 1);
            chessboard[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        chessboard = vector<string>(n, string(n, '.'));
        ans.clear();
        search(n, 0);
        return ans;
    }
};

int main() {
    int n = 4;
    Solution solution;
    solution.solveNQueens(n);
}