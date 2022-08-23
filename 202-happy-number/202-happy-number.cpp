class Solution {
public:
    
    bool isHappy(int n) {
        unordered_set<int> s;
        while( 1 ) {
            int t = 0;
            while(n>0) {
                t+= (n%10)*(n%10);
                n= n/10;
            }
            if( t==1 )
                return true;
            if( s.find(t)!=s.end() ) {
                return false;
            }
            s.insert(t);
            n = t;
        }
    }
};