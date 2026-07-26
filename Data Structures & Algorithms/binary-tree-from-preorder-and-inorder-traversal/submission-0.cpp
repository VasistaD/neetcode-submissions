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
    int i=0;
    unordered_map<int,int> hashMap;
    TreeNode* bosdTree(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if(l > r)
            return nullptr;
        int val = preorder[i++];
        TreeNode* newNode = new TreeNode(val);
        int split = hashMap[val];
        newNode->left = bosdTree(preorder, inorder, l, split-1);
        newNode->right = bosdTree(preorder, inorder, split+1, r);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0;i<n;i++)
            hashMap[inorder[i]] = i;
        return bosdTree(preorder, inorder, 0, n-1);
    }
};
