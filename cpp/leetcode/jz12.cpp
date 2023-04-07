#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param matrix char�ַ���vector<vector<>>
     * @param word string�ַ���
     * @return bool������
     */
    bool hasPath(vector<vector<char> >& matrix, string word) {
        // write code here
        int n = matrix.size(), m = matrix[0].size();
        if (m == 0 || n == 0) return false;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                vector<vector<bool>> flag(n, vector<bool>(m, true));
                if (search(flag, matrix, word, 0, row, col)) return true;
            }
        }
        return false;
    }
private:
    bool search(vector<vector<bool>>& flag, vector<vector<char>>& mat, string& word,
        int index, int row, int col) {
        if (mat[row][col] != word[index]) return false;
        if (index == word.size() - 1) return true;
        flag[row][col] = false;
        int n = mat.size() - 1, m = mat[0].size() - 1;
        if (row > 0 && flag[row - 1][col] &&
            search(flag, mat, word, index + 1, row - 1, col)) return true;
        if (row < n && flag[row + 1][col] &&
            search(flag, mat, word, index + 1, row + 1, col)) return true;
        if (col > 0 && flag[row][col - 1] &&
            search(flag, mat, word, index + 1, row, col - 1)) return true;
        if (col < m && flag[row][col + 1] &&
            search(flag, mat, word, index + 1, row, col + 1)) return true;
        flag[row][col] = true;
        return false;
    }
};

int main() {
    vector<vector<char>> mat = { {'A', 'B', 'C'}, {'B', 'E', 'D'}, {'F','G', 'G'} };
    Solution solution;
    bool ans = solution.hasPath(mat, "ABCDEBF");
    cout << ans << endl;
}