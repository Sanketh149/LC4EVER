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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(!nums.size()) return NULL;
        int maxi = -1e9, idx = -1, n = nums.size();
        for(int i = 0;i<n;i++)
        {
            if(maxi < nums[i])
            {
                maxi = nums[i];
                idx = i;
            }
        }
        TreeNode *root = new TreeNode(maxi);
        vector<int>res(nums.begin(), nums.begin()+idx);
        root->left = constructMaximumBinaryTree(res);
        vector<int>res2(nums.begin()+idx+1, nums.begin()+n);
        root->right = constructMaximumBinaryTree(res2);
        return root;
    }
};