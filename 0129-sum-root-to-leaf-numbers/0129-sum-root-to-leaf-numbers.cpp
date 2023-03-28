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
    int rec(TreeNode *root, int sum)
    {
        if(!root) return 0;
        if(root->left == NULL and root->right == NULL) return sum*10+root->val;
        sum = sum*10 + root->val;
        int l = rec(root->left, sum);
        int r = rec(root->right, sum);
        return (l+r);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return rec(root, sum);
    }
};