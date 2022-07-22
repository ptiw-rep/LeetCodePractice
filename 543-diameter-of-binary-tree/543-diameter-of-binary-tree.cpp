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
    int height(TreeNode* root, int &mx) {
        if( root==NULL )
            return 0;
        int l = height(root->left,mx);
        int r = height(root->right,mx);
        mx = max( mx,l+r );
        return 1+ max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int mx = 0;
        height(root,mx);
        return mx;
    }
};