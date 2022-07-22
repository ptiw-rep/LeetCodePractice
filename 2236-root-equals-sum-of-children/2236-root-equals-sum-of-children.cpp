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
        // go for left subtree and right subtree
        int l = csum(root->left,flag);
        int r = csum(root->right,flag);
        // we have to make sure that we dont check it for leaf nodes ( as it will return 0,0 )
        // and leaf nodes are always following csum property 
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