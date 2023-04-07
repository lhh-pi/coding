#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void search(vector<int>& nums, int start, int target) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        else if (target < 0) return;
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            search(nums, i, target - nums[i]);
            path.erase(path.end() - 1);

        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        search(candidates, 0, target);
        return ans;
    }
};