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
    int maxDiameter = 0;
    int diameterOfBT(TreeNode* root) {
        if(!root)
            return 0;
        int leftHeight=0,rightHeight=0;
        if(root->left)
            leftHeight = 1 + diameterOfBT(root->left);
        if(root->right)
            rightHeight = 1 + diameterOfBT(root->right);
        maxDiameter = max(maxDiameter,leftHeight+rightHeight);
        return max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        diameterOfBT(root);
        return maxDiameter;
    }
};
