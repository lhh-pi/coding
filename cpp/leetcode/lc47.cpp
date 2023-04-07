#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
	vector<vector<int>> ans;
	vector<int> path;
	void search(vector<int>& nums, vector<bool>& used) {
		if (path.size() == nums.size()) {
			ans.push_back(path);
			return;
		}
		unordered_set<int> usedVal;
		for (int i = 0; i < nums.size(); i++) {
			if (used[i] || usedVal.count(nums[i])) continue;
			path.push_back(nums[i]);
			used[i] = true;
			usedVal.insert(nums[i]);
			search(nums, used);
			used[i] = false;
			path.pop_back();
		}
	}
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		ans.clear();
		path.clear();
		vector<bool> used(nums.size(), false);
		search(nums, used);
		return ans;
	}
};

int main() {
}