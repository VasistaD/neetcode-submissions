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
    int maxSum;
    int dfs(TreeNode* node) {
        if(!node)
            return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        maxSum = max(maxSum,node->val+left+right);
        return max(0,node->val+max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        maxSum = root->val;
        int a = dfs(root);
        return maxSum;
    }
};
