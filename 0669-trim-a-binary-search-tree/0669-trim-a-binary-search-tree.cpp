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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return NULL;
        if(root->val >= low and root->val <= high)
        {
            TreeNode *res = new TreeNode(root->val);
            res->left = trimBST(root->left, low, high);
            res->right = trimBST(root->right, low, high);
            return res;
        }
        if(root->val > high)
        {
            return trimBST(root->left, low, high);
        }
        if(root->val < low)
        {
            return trimBST(root->right, low, high);
        }
        return NULL;
    }
};