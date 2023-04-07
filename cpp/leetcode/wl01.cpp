#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int>& nums) {
	vector<int> ans(nums.size(), 1);
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums.size(); j++)
			if (i != j) ans[i] *= nums[j];
	}
	return ans;
}

int main() {
	vector<int> nums{1, 2, 3, 4};
	vector<int> output = solution(nums);
	for (int val : output) cout << val << " ";
	cout << endl;
}