#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ans = INT_MIN;
		int start = 0;
		while (start < nums.size() && nums[start] <= 0) {
			ans = max(ans, nums[start++]);
		}
		if (start == nums.size()) return ans;
		int cur = 0;
		for (int i = start; i < nums.size(); i++) {
			if (nums[i] + cur >= 0) {
				cur += nums[i];
				ans = max(ans, cur);
			}
			else {
				ans = max(ans, cur);
				cur = 0;
			}
		}
		return ans;
	}
};