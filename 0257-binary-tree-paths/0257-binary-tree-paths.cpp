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
    void rec(TreeNode *root, vector<string> &res, string temp)
    {
        if(!root->left and !root->right)
        {
            res.push_back(temp);
            return;
        }
        if(root->left)
            rec(root->left, res, temp+"->"+to_string(root->left->val));
        if(root->right)
            rec(root->right, res, temp+"->"+to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        string temp = to_string(root->val);
        rec(root, res, temp);
        return res;
    }
};