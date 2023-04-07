#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<int> ans;
	int row;
	cin >> row;
	while (row--) {
		int flag = 0;
		vector<int> arr;
		int count = 0;
		string input;
		cin >> input;
		int i = 0;
		while (i < input.size()) {
			int lower = 0, capital = 0;
			while (i < input.size() && input[i] > 'Z') {
				lower++;
				i++;
			}
			if (flag == 0 || lower == 0) count += lower;
			else if (flag == 1) {
				count += lower + 1;
				if (lower > 1) flag = 0;
			}

			while (i < input.size() && input[i] < 'a') {
				capital++;
				i++;
			}
			if (flag == 1 || capital == 0) count += capital;
			else if (flag == 0) {
				count += capital + 1;
				if (capital > 1) flag = 1;
			}
		}

		ans.push_back(count);
	}

	for (int num : ans) {
		cout << num << endl;
	}

}