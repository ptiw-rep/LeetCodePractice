/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>( n,-1));
        int left = 0, right = n-1;
        int top = 0, bottom = m-1;
        int mov, dir = 0;
        ListNode *nptr = head;
        while( top<=bottom && left<=right && nptr!=NULL) {
            if( dir==0 ) {
                mov = left;
                while( nptr!=NULL && mov<=right ) {
                    ans[top][mov] = nptr->val;
                    nptr = nptr->next;
                    mov++;
                }
                top++;
            }
            else if( dir==1 ) {
                mov = top;
                while( nptr!=NULL && mov<=bottom ) {
                    ans[mov][right] = nptr->val;
                    nptr= nptr->next;
                    mov++;
                }
                right--;
            }
            else if( dir==2 ) {
                mov = right;
                while( nptr!=NULL && mov>=left ) {
                    ans[bottom][mov] = nptr->val;
                    nptr= nptr->next;
                    mov--;
                }
                bottom--;
            }
            else {
                mov = bottom;
                while( nptr!=NULL && mov>=top ){
                    ans[mov][left] = nptr->val;
                    nptr= nptr->next;
                    mov--;
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
};