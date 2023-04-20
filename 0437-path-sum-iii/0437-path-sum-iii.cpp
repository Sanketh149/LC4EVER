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
    int totalpaths = 0;
    void rec(TreeNode *root, long target)
    {
        if(!root) return;
        if(target == root->val) totalpaths++;
        rec(root->left, target-root->val);
        rec(root->right, target-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        rec(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return totalpaths;
    }
};