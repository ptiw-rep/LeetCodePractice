class Solution {
public:
    // decoding
    // char dec = key[i]
    string decodeMessage(string key, string message) {
        string ans = "";
        map<char,char> mp;
        int charCount = 0;
        // map character with atleast one match to value
        for( int i=0;i<key.size();i++ ) {
            if( charCount==26 )
                break;
            if( key[i]==' ' || mp.find(key[i])!=mp.end()  )
                continue;
            else{
                mp[key[i]] = 'a' + charCount;
                charCount++;
            }
        }
        for( char ch : message ) {
            if( ch==' ' )
                ans+=' ';
            else
                ans+=mp[ch];
        }
        return ans;
    }
};