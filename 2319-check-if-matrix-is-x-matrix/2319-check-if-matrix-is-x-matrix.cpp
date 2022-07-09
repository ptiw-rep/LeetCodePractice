class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int i, j, n = grid.size();
        // for diagonal i,j will be either i==j or i+j = n-1
        for( i=0;i<n;i++ ) {
            for( j=0;j<n;j++ ) {
                if( i==j || i+j==n-1 ) {
                    // is diagonal
                    if( grid[i][j]==0 )
                        return false; 
                }
                else {
                     if( grid[i][j]!=0 )
                        return false;
                }
            }
        }
        return true;
    }
};