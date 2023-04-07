#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:
    int search(vector<vector<int>>& mat, vector<vector<bool>>& flag, int row,
        int col) {
        int ans = 0;
        int n = mat.size(), m = mat[0].size();
        flag[row][col] = false;

        if (row > 0 && flag[row - 1][col] && mat[row - 1][col] > mat[row][col])
            ans = max(ans, search(mat, flag, row - 1, col));

        if (row < n - 1 && flag[row + 1][col] && mat[row + 1][col] > mat[row][col])
            ans = max(ans, search(mat, flag, row + 1, col));

        if (col > 0 && flag[row][col - 1] && mat[row][col - 1] > mat[row][col])
            ans = max(ans, search(mat, flag, row, col - 1));

        if (col < m - 1 && flag[row][col + 1] && mat[row][col + 1] > mat[row][col])
            ans = max(ans, search(mat, flag, row, col + 1));

        flag[row][col] = true;
        return ans + 1;
    }
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    int solve(vector<vector<int> >& matrix) {
        // write code here
        int ans = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> flag(n, vector<bool>(m, true));
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                ans = max(ans, search(matrix, flag, row, col));
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> m = { {4,3,3,6,6,3,2,1,0,7},{1,8,2,8,5,9,2,8,3,1},{8,0,9,2,4,3,2,4,3,7},{1,2,2,6,3,0,3,9,7,0},{7,4,3,8,8,3,2,4,6,8},{2,8,9,2,9,3,0,8,7,8},{8,9,9,4,6,3,3,4,9,6},{2,8,3,8,1,3,7,3,0,7},{2,1,1,6,4,1,0,8,1,6},{4,1,3,6,3,4,4,4,0,3} };
    Solution solution;
    int ans = solution.solve(m);
    cout << ans << endl;
}