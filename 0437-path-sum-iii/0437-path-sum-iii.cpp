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
    int res = 0, sum;
    unordered_map<long, int> mp;
    void dfs(TreeNode* root, long partialSum = 0) {
        // updating partialSum with the current node
        partialSum += root->val;
        // checking if we already found an interval summing up to that
        res += mp[partialSum - sum];
        // updating seen
        mp[partialSum]++;
        // searching potential left and right branches
        if (root->left) dfs(root->left, partialSum);
        if (root->right) dfs(root->right, partialSum);
        // clearing seen of the last value, for backtracking purposes
        mp[partialSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        sum = targetSum;
        // seen set with initial value 0 will help us match from the root
        mp[0] = 1;
        if (!root) return 0;
        dfs(root);
        return res;
    }
};