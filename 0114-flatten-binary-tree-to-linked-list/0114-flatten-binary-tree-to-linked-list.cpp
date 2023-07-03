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
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode *currLeft = root->left;
        if(!currLeft) flatten(root->right);
        else
        {
            while(currLeft->right) currLeft = currLeft->right;
            currLeft->right = root->right;
            root->right = root->left;
            root->left = NULL;
            flatten(root->right);
        }
    }
};