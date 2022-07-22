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
    
    int csum(TreeNode* root,bool &flag) {
        if( root==NULL )
            return 0;
        int l = csum(root->left,flag);
        int r = csum(root->right,flag);
        if( (root->left || root->right) && (l+r!= root->val) )
            flag = false;
        return root->val;
    }
    bool checkTree(TreeNode* root) {
        bool flag = true;
        csum(root,flag);
        return flag;
    }
};