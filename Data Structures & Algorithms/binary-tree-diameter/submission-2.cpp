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
        int leftHeight=getDia(root->left);
        int rightHeight=getDia(root->right);;

        maxHeight = max(maxHeight,leftHeight+rightHeight);
        return 1 + max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getDia(root);
        return maxHeight;
    }
};
