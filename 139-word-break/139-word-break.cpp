class Solution {
public:
    // bool solve(int i, string &s, unordered_set<string> &hash, vector<int> &dp ){
    //     if( i==s.size() ){
    //         return true;
    //     }
    //     if( dp[i]!=-1 )
    //         return dp[i];
    //     string curr="";
    //     for(int k=i;k<s.size();k++){
    //         curr+=s[k];
    //         if( solve(k+1,s,hash,dp) && hash.find(curr)!=hash.end() )
    //             return dp[i]=true;
    //     }
    //     return dp[i]=false;
    // }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash(wordDict.begin(),wordDict.end());
        int i,k,n = s.size();
        vector<bool> dp(n+1, false);
        // base case
        dp[n] = true;
        for(i=n-1;i>=0;i--) {
            string curr = "";
            for(k=i;k<n;k++) {
                curr+=s[k];
                if( dp[k+1] && hash.find(curr)!=hash.end() )
                    dp[i] = true;
            }
        }
        return dp[0];
    }
};