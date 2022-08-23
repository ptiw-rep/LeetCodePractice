class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pf = "";
        int n = strs.size();
        int m = -1,ms=INT_MAX;
        for( int i=0;i<n;i++ ) {
            if( strs[i].size() < ms ) {
                ms = strs[i].size();
                m = i;
            }    
        }
        for( int i=0;i<strs[m].size();i++ ) {
            for( int j=0;j<n;j++ ) {
                if( strs[m][i]!= strs[j][i] ) {
                    return pf;
                }
            }
            pf+= strs[m][i];
        }
        return pf;
    }
};