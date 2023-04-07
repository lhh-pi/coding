#include <iostream>
#include <vector>

using namespace std;

class Solution {
	vector<int> path;
	vector<vector<int>> ans;
public:
	void search(vector<int> nums, int k) {
		if (k == 0) return;
		for (int i = 0; i < nums.size(); i++) {
			int val = nums[i];
			nums.erase(nums.begin() + i);
			path.push_back(val);
			if (k == 0) {
				ans.push_back(path);
			}
			search(nums, k - 1);
			path.erase(path.end() - 1);
			nums.insert(nums.begin() + i, val);
		}
	}
	vector<vector<int>> combine(int n, int k) {
		vector<int> nums;
		for (int i = 1; i <= n; i++) {
			nums.push_back(i);
		}

		search(nums, k);
		return ans;
	}
};
