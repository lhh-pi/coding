#include <vector>

using namespace std;

class Solution {
private:
    vector<int> subset;
    vector<vector<int>> ans;
    void search(vector<int>& nums, int index) {
        if (index == nums.size()) return;
        for (int i = 0; i < 2; i++) {
            if (i == 1) {
                subset.push_back(nums[index]);
                ans.push_back(subset);
            }

            search(nums, index + 1);
            if (i == 1) subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        subset.clear();
        ans.clear();
        ans.push_back(subset);
        search(nums, 0);
        return ans;
    }
};

int main() {
    vector<int> nums = { 1, 2, 3 };
    Solution solution;
    solution.subsets(nums);
}