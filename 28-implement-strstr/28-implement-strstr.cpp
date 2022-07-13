class Solution {
public:
    void preCompute(string &pat, vector<int> &lps) {
        int i=1, len = 0, n = pat.size();
        while(i<n) {
            if(pat[i]==pat[len]){
                // len++;
                // lps[i]=len;
                // i++;
                lps[i++] = ++len;
            }
            else{
                if(len>0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    int strStr(string haystack, string needle) {
        int n = haystack.size(),  m = needle.size();
        vector<int> lps(m,0);
        preCompute(needle,lps);
        int i=0, j=0;
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==m)
                return i-j;
            else if( i<n && haystack[i]!=needle[j]){
                // if( j>0 ){
                //     j = lps[j-1];
                // }
                // else {
                //     i++;
                // }
                j ? j= lps[j-1] : i++;
            }
        }
        return -1;
    }
};