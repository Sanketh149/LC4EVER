/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(cloned->val == target->val) return cloned;
        if(cloned->left) 
        {   
                TreeNode* curr =  getTargetCopy(original, cloned->left, target);
                if(curr and curr->val == target->val) 
                    return curr;
        }
        if(cloned->right)  
        {
            TreeNode* curr =  getTargetCopy(original, cloned->right, target);
            if(curr and curr->val == target->val) 
                return curr;
        }
        return NULL;
    }
};