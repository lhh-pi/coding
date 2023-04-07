#include <iostream> 
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool isShuxianhua(int num) {
	int ans = 0, n = num;
	while (1) {
		int n = num % 10;
		ans += n * n * n;
		num /= 10;
		if (num == 0) break;
	}
	return ans == n;
}

int main() {
	string input;
	vector<vector<int>> ans;
	while (getline(cin, input)) {
		if (input.size() == 0) break;
		int m = 0, n = 0;

		stringstream strin(input);
		strin >> m;
		strin >> n;

		vector<int> row;
		for (int i = m; i <= n; i++) {
			if (isShuxianhua(i)) {
				row.push_back(i);
			}
		}
		if (row.size() == 0) row.push_back(-1);
		ans.push_back(row);
	}

	for (vector<int> row : ans) {
		for (int num : row) {
			if (num == -1) {
				cout << "no";

			}
			else {
				cout << num << " ";
			}
		}
		cout << endl;
	}
}