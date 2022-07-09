class Solution {
public:
    int numSplits(string s) {
        int count=0, n = s.size();
        // make two arrays, pref and post that have number of letters unique letter to left(including) and to right.
        vector<int> pre(n),post(n);
        pre[0] = post[n-1] = 1;
        vector<bool> a(26,false),b(26,false);
        a[s[0]-'a'] = true;
        b[s[n-1]-'a'] = true;
        for( int i=1;i<n;i++ ) {
            char left = s[i], right = s[n-1-i];
            if( a[left-'a'] ){
                pre[i] = pre[i-1];
            }
            else{
                pre[i] = pre[i-1] + 1;
                a[left-'a'] = true;
            }
            
            if( b[right-'a'] ){
                post[n-i-1] = post[n-i];
            }
            else{
                post[n-i-1] = post[n-i] + 1;
                b[right-'a'] = true;
            }
        }
        for( int i=0;i<n-1;i++ ){
            if( pre[i]==post[i+1] )
                count++;
        }
        return count;
    }
};