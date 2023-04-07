#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();
        int val = postorder[size - 1];
        TreeNode* root = new TreeNode(val);
        if (size == 1) return root;
        vector<int>::iterator iter = find(inorder.begin(), inorder.end(), val);
        vector<int> left_inorder(inorder.begin(), iter);
        vector<int> right_inorder(iter + 1, inorder.end());
        vector<int> left_postorder(postorder.begin(), postorder.begin() + left_inorder.size());
        vector<int> right_postorder(postorder.begin() + left_inorder.size(), postorder.end() - 1);


        if (left_inorder.size()) {
            TreeNode* left = buildTree(left_inorder, left_postorder);
            root->left = left;
        }
        if (right_inorder.size()) {
            TreeNode* right = buildTree(right_inorder, right_postorder);
            root->right = right;
        }
        return root;
    }
};

int main() {
    vector<int> inorder = { 9, 3, 15, 20, 7 }, postorder = { 9, 15, 7, 20, 3 };
    Solution solution;
    TreeNode* root = solution.buildTree(inorder, postorder);
}