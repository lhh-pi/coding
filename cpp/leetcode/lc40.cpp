#include <vector>
#include <algorithm>

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
            if (i > start && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            int newTarget = target - nums[i];
            search(nums, i + 1, newTarget); 
            path.erase(path.end() - 1);
            if (newTarget < 0) return;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        search(candidates, 0, target);
        return ans;
    }
};