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
    int height(TreeNode *root, int &maxi)
    {
        if(!root) return 0;
        int lpath = max(0, height(root->left, maxi));
        int rpath = max(0, height(root->right, maxi));
        maxi = max(maxi, root->val+lpath+rpath);
        return max(lpath,rpath)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxi = -1e9;
        height(root, maxi);
        return maxi;
    }
};