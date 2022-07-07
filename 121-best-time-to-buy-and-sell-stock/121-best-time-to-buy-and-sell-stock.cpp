class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=1, mnVal = prices[0], ans = 0;
        for( i=1;i<prices.size();i++ ) {
            ans = max( ans, prices[i]- mnVal );
            mnVal = min( mnVal , prices[i] );
        }
        return ans;
    }
};