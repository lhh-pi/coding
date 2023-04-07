#include <vector>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		int right = nums[0], left = 0;
		int ans = 1;
		int nextRight = right;
		while (right < nums.size() - 1) {
			while (left <= right) {
				int nextPoint = nums[left] + left++;
				if (nextPoint > nextRight) {
					nextRight = nextPoint;
				}
			}
			right = nextRight;
			ans++;
		}
		return ans;
	}
};