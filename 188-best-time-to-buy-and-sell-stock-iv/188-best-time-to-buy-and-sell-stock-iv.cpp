class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int i,buy,cap,n=prices.size();
        vector<vector<int>> after(2,vector<int> (k+1,0));
        vector<vector<int>> curr(2,vector<int> (k+1,0));
        for( i=n-1;i>=0;i-- ) {
            for( buy=0;buy<2;buy++ ) {
                for( cap=1;cap<=k;cap++ ) {
                    if( buy )
                        curr[buy][cap] = max( -prices[i]+after[0][cap],after[1][cap]);
                    else
                        curr[buy][cap] = max( prices[i]+after[1][cap-1],after[0][cap]);
                }
            }
            after = curr;
        }
        return curr[1][k];
    }
};