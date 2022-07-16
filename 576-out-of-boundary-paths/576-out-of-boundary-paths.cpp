class Solution {
public:
    const int mod = 1e9 + 7;
    bool isValid(int i, int j, int m , int n) {
        if( i<0 || j<0 || j>=n || i>=m )
            return false;
        return true;
    }
    int solve(int i ,int j , int m , int n, int moves,vector<vector<vector<int>>> &dp) {
        if( !isValid(i,j,m,n) )
            return 1;
        if( moves<= 0 )
            return 0;
        if( dp[i][j][moves]!=-1)
            return dp[i][j][moves];
        else {
            return dp[i][j][moves] = ((solve(i+1,j,m,n,moves-1,dp)%mod+solve(i-1,j,m,n,moves-1,dp)%mod)%mod+(solve(i,j+1,m,n,moves-1,dp)%mod+solve(i,j-1,m,n,moves-1,dp)%mod)%mod)%mod;
        }
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return solve(startRow,startColumn,m,n,maxMove,dp);
    }
};