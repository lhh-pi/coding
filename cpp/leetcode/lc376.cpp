#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        if (nums.size() == 2) return nums[0] == nums[1] ? 1 : 2;
        int pre_res, cur_res, pre = nums[0];

        int index = 1;
        while (nums[index] == pre && index < nums.size()) index++;
        if (index == nums.size()) return 1;

        pre_res = nums[index] - nums[0];
        pre = nums[index];
        int ans = 2;

        for (int i = index + 1; i < nums.size(); i++) {
            cur_res = nums[i] - pre;
            if (pre_res * cur_res > 0) {
                pre = nums[i];
            }
            else if (pre_res * cur_res < 0) {
                pre = nums[i];
                ans++;
                pre_res = cur_res;
            }
        }
        return ans;
    }
};