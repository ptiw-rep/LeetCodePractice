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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {          
        vector<vector<int>> zzlt;
        if( root==NULL )
            return zzlt;
        queue<TreeNode*> q;
        q.push(root);
        bool rev = false;
        while( !q.empty() ) {
            int k = q.size();
            vector<int> lvl(k);
            for( int i=0;i<k;i++ ) {
                TreeNode* temp = q.front();
                q.pop();
                if( rev ) {
                    lvl[k-1-i] = temp->val;
                }
                else{
                    lvl[i] = temp->val;
                }
                if( temp->left ) 
                    q.push(temp->left);
                if( temp->right ) 
                    q.push(temp->right);
            }
            zzlt.push_back(lvl);
            rev = !rev;
        }
        return zzlt;
    }
};