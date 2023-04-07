#include <vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() == 1) return true;
		int right = nums[0], cur = 0;
		while (cur <= right && right < nums.size() - 1) {
			right = max(nums[cur] + cur, right);
			cur++;
		}
		return right >= nums.size() - 1;
	}
};