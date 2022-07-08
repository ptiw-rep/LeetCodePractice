class Solution {
public:
    int m = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1,0); 
        dp[1]= 1;
        // sh = people sharing secret
        // newShare = wo log jinko naya secret pata laga h
        // forgot = wo log jo secret bhul gye h
        long long int sh = 0, newShare,forgot,ans=0;
        for( int i =2;i<=n;i++ ) {
            newShare = dp[max(i-delay,0)];
            forgot = dp[max(i-forget,0)];
            sh = (sh + newShare - forgot+m)%m;
            dp[i] = sh;
        }
        // ans hoga, jitne logo ko secret yaad h, to wo h ki n- forget tk jate jao n se aur sum kr lo
        for( int i = n-forget+1;i<=n;i++) 
            ans=(ans+dp[i])%m;
        return ans; 
    }
};