#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> subset;
    vector<vector<int>> ans;
    void search(vector<int>& nums, int start) {
        ans.push_back(subset);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            search(nums, i + 1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        subset.clear();
        ans.clear();
        sort(nums.begin(), nums.end());
        search(nums, 0);
        return ans;
    }
};

int main() {
    vector<int> nums = { 1, 2, 2 };
    Solution solution;
    solution.subsetsWithDup(nums);
}