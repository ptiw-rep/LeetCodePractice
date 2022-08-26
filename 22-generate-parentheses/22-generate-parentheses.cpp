class Solution {
public:
    void util(int open, int close, string curr, int n, vector<string> &res) {
        if( curr.length()==n*2 ){
            res.push_back(curr);
            return;
        }
        if( open<n ) 
            util(open+1,close,curr+"(",n,res);
        if( close<open )
            util(open,close+1,curr+")",n,res);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        util(0,0,"",n,res);
        return res;
    }
};