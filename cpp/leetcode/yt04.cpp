#include <iostream>
#include <vector>

using namespace std;

void getMatrix(int n, int m, vector<vector<int>>& mat) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
}

vector<vector<int>> inverse(vector<vector<int>>& mat) {
	int row = mat.size();
	int col = mat[0].size();
	vector<vector<int>> ans(col, vector<int>(row, 0));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			ans[j][i] = mat[i][j];
		}
	}
	return ans;
}

vector<vector<int>> multi(vector<vector<int>>& m1, vector<vector<int>>& m2) {
	int row = m1.size(), col = m2[0].size();
	vector<vector<int>> m(row, vector<int>(col, 0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			for (int k = 0; k < m2.size(); k++) {
				m[i][j] += m1[i][k] * m2[k][j];
				m[i][j] = m[i][j] % 1009;
			}
		}
	}
	return m;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> A(n, vector<int>(m, 0));
	vector<vector<int>> B(n, vector<int>(m, 0));
	getMatrix(n, m, A);
	getMatrix(n, m, B);

	vector<vector<int>> ans;
	ans = inverse(A);
	ans = multi(ans, B);
	vector<vector<int>> BT = inverse(B);
	ans = multi(ans, BT);
	ans = inverse(ans);
	cout << ans.size() << " " << ans[0].size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[0].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}