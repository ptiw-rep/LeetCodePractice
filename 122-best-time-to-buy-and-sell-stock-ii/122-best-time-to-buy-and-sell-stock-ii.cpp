class Solution {
public:
    // int solve(vector<int>& prices, int i, bool buy,vector<vector<int>> &dp) {
    //     if( i==prices.size() )
    //         return 0;
    //     if( dp[i][buy]!=-1)
    //         return dp[i][buy];
    //     if( buy )
    //         return dp[i][buy]=max(-prices[i]+ solve(prices,i+1,0,dp) , solve(prices,i+1,1,dp));
    //     else
    //         return dp[i][buy]=max(prices[i]+ solve(prices,i+1,1,dp), solve(prices,i+1,0,dp));
    // }
    int maxProfit(vector<int>& prices) {
        int i,buy,n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        for(i=n-1;i>=0;i-- ) {
            for( buy=0;buy<2;buy++ ) {
                if( buy )
                    dp[i][buy] = max( -prices[i]+ dp[i+1][0],dp[i+1][1]);
                else
                    dp[i][buy] = max( prices[i]+ dp[i+1][1],dp[i+1][0]);
            }
        }
        return dp[0][1];
    }
};