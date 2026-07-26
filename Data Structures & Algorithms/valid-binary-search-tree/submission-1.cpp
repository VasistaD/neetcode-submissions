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
    int maxVal = INT_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        bool isLeftBST = isValidBST(root->left);
        if(root->val <= maxVal)
            return false;
        maxVal = root->val;
        bool isRightBST = isValidBST(root->right);
        return isLeftBST && isRightBST;
        
    }
};
