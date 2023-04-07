#include <vector>
using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int size = nums.size();
        int ans = 0;
        for (int i = 0; i < size - 2; i++) {
            for (int j = i + 1; j < size - 1; j++) {
                int cur_diff = nums[j] - nums[i];
                if (cur_diff < diff) continue;
                else if (cur_diff > diff) break;
                for (int k = j + 1; k < size; k++) {
                    if (nums[k] - nums[j] < diff) continue;
                    else if (nums[k] - nums[j] > diff) break;
                    else {
                        ans += 1;
                        break;
                    }
                }
                break;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = { 0, 1, 4, 6, 7, 10 };
    int diff = 3;
    Solution solution;
    solution.arithmeticTriplets(nums, diff);
}