/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void rev(TreeNode *left, TreeNode *right, bool flip)
    {
        if(!left or !right) return;
        if(flip)
            swap(left->val, right->val);
        rev(left->left, right->right, !flip);
        rev(left->right, right->left, !flip);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        rev(root->left, root->right, true);
        return root;
    }
};