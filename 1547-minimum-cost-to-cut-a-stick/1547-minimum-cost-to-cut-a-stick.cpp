class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));
        int i, j, idx;
        for( i=c;i>0;i--){
            for( j=i;j<=c;j++ ){
                int ans = INT_MAX;
                for( idx=i;idx<=j;idx++){
                    ans = min(ans, cuts[j+1]-cuts[i-1]+ dp[i][idx-1]+ dp[idx+1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][c];
    }
};