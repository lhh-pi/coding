#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    vector<int> subset;
    set<vector<int>> ans;
    void search(vector<int>& nums, int start) {
        if (subset.size() > 1) ans.insert(subset);
        for (int i = start; i < nums.size(); i++) {
            if (start > 0 && nums[i] < nums[start - 1]) continue;
            subset.push_back(nums[i]);
            search(nums, i + 1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        subset.clear();
        ans.clear();
        search(nums, 0);
        vector<vector<int>> vans;
        for (vector<int> v : ans) {
            vans.push_back(v);
        }
        return vans;
    }
};

int main() {
    vector<int> nums = { 4, 6, 6, 7 };
    Solution solution;
    solution.findSubsequences(nums);
}