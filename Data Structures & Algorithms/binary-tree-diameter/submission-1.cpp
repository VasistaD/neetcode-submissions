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
    int maxHeight=0;
    int getDia(TreeNode* root) {
        if(!root)
            return 0;
        int leftHeight=0,rightHeight=0;
        if(root->left)
            leftHeight = 1 + getDia(root->left);
        if(root->right)
            rightHeight = 1 + getDia(root->right);
        maxHeight = max(maxHeight,leftHeight+rightHeight);
        return max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getDia(root);
        return maxHeight;
    }
};
