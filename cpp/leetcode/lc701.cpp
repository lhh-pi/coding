#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left, * right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

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
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		TreeNode* node = new TreeNode(val);
		if (!root) return node;
		TreeNode* cur = root;

		while (true) {
			if (val > cur->val) {
				if (cur->right)
					cur = cur->right;
				else break;
			}
			else {
				if (cur->left) cur = cur->left;
				else break;
			}
		}
		if (val > cur->val) cur->right = node;
		else cur->left = node;
		return root;
	}
};

int main() {
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	Solution solution;
	solution.insertIntoBST(root, 5);
	root->traval();
}
