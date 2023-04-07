#include <iostream>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left, * right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (!root) return root;
		if (root->val < low) return trimBST(root->right, low, high);
		if (root->val > high) return trimBST(root->left, low, high);
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		return root;
	}
};