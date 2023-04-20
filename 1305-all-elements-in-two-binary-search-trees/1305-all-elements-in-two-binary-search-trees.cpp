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
    void inorder(TreeNode *root, vector<int> &res)
    {
        if(!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>l1, l2;
        inorder(root1, l1);
        inorder(root2, l2);
        int m = l1.size(), n = l2.size();
        vector<int>allElements;
        int i = 0, j = 0;
        while(i<m and j<n)
        {
            if(l1[i] <= l2[j])
            {
                allElements.push_back(l1[i]);
                i++;
            }
            else{
                allElements.push_back(l2[j]);
                j++;
            }
        }
        while(i<m)
        {
            allElements.push_back(l1[i]);
            i++;
        }
        while(j < n)
        {
            allElements.push_back(l2[j]);
            j++;
        }
        return allElements;
    }
};