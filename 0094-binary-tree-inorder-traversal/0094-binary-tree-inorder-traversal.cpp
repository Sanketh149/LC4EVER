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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode *curr = root;
        while(curr)
        {
            if(!curr->left)
            {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode *next = curr->left;
                while(next->right and next->right != curr)
                {
                    next = next->right;
                }
                if(next->right == NULL)
                {
                    next->right = curr;
                    curr = curr->left;
                }
                else{
                    next->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};