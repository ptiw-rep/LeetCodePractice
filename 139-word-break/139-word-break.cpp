class Solution {
public:
    bool solve(int i, string &s, unordered_set<string> &hash, vector<int> &dp ){
        if( i==s.size() ){
            return true;
        }
        if( dp[i]!=-1 )
            return dp[i];
        string curr="";
        for(int k=i;k<s.size();k++){
            curr+=s[k];
            if( solve(k+1,s,hash,dp) && hash.find(curr)!=hash.end() )
                return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size(),-1);
        return solve(0,s,hash,dp);
    }
};