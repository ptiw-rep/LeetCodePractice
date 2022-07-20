class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(1e4 + 1,0), dp(1e4 + 1);
        // dp[i] represents maxEarn from 1,2,3... i
        // So the recurrence relation will be
        // dp[i] = max(freq[i]*i + dp[i-2] // Pick, dp[i-1] // Do not pick )
        for( int num : nums )
            count[num]++;
        dp[0] = 0;
        dp[1]= count[1];
        for( int i=2;i<1e4+1;i++ ){
            dp[i] = max(count[i]*i + dp[i-2], dp[i-1] ); 
        }
        return dp[1e4];
    }
};