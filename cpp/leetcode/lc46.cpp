#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;

    void search(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            search(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        path.clear();
        ans.clear();
        vector<bool> used(nums.size(), false);
        search(nums, used);
        return ans;
    }
};