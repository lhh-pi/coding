#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left, * right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int mid = nums.size() / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		if (mid == 0) return root;

		if (mid > 0) {
			vector<int> left(nums.begin(), nums.begin() + mid);
			root->left = sortedArrayToBST(left);
		}
		if (mid + 1 < nums.size()) {
			vector<int> right(nums.begin() + mid + 1, nums.end());
			root->right = sortedArrayToBST(right);
		}
		
		return root;
	}
};