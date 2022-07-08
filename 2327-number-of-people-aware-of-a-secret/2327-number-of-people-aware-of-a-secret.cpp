class Solution {
public:
    int m = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1,0); 
        dp[1]= 1;
        long long int sh = 0, newShare,forgot,ans=0;
        for( int i =2;i<=n;i++ ) {
            newShare = dp[max(i-delay,0)];
            forgot = dp[max(i-forget,0)];
            sh = (sh + newShare - forgot+m)%m;
            dp[i] = sh;
        }
        for( int i = n-forget+1;i<=n;i++) 
            ans=(ans+dp[i])%m;
        return ans; 
    }
};