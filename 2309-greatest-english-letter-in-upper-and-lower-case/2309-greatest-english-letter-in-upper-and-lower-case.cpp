class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> lower(26,0), upper(26,0);
        for( char ch : s ) {
            // uppercase
            if( ch>64 &&ch <91 ) 
                upper[ch-'A'] = true;
            else
                lower[ch-'a'] = true;
        }
        string ans="";
        for( int i=25;i>=0;i-- ) {
            if( lower[i] &&upper[i] ) {
                ans+=(i+'A');
                break;
            }
        }
        return ans;
    }
};