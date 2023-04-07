#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left, * right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

	void traval() {
		queue<TreeNode*> q;
		TreeNode* root = this;
		if (root) q.push(root);
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				TreeNode* node = q.front();
				q.pop();
				cout << node->val << " ";
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
	}
};

class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int val) {
		if (root && root->val == val) {
			TreeNode* right = root->right;
			if (!right) return root->left;
			else {
				TreeNode* left = root->left;
				root = right;
				while (right->left) {
					right = right->left;
				}
				right->left = left;
				return root;
			}
		}
		TreeNode* cur = root;
		while (cur) {
			if (cur->val > val) {
				if (cur->left && cur->left->val == val) {
					TreeNode* right = cur->left->right;
					if (!right) cur->left = cur->left->left;
					else {
						TreeNode* left = cur->left->left;
						cur->left = right;

						while (right->left) {
							right = right->left;
						}
						right->left = left;
					}
					break;
				}

				else cur = cur->left;
			}

			else if (cur->val < val) {
				if (cur->right && cur->right->val == val) {
					TreeNode* right = cur->right->right;
					if (!right) cur->right = cur->right->left;
					else {
						TreeNode* left = cur->right->left;
						cur->right = right;

						while (right->left) {
							right = right->left;
						}
						right->left = left;
					}
					break;
				}

				else cur = cur->right;
			}
		}
		return root;
	}
};
