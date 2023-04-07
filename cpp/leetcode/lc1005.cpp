#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, ans = 0;
        while (nums[i] < 0 && i < nums.size() && k--) {
            nums[i] = -nums[i];
            ans += nums[i++];
        }
        if (k % 2 == 1) {
            if (i == 0) {
                nums[0] = -nums[0];
            }
            else {
                int min = nums[i - 1];
                if (i < nums.size() && nums[i] < nums[i - 1]) min = nums[i];
                ans -= 2 * min;
            }
        }
        for (; i < nums.size(); i++) {
            ans += nums[i];
        }
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> nums{ 4,3,2 };
    int k = 1;
    solution.largestSumAfterKNegations(nums, k);
}