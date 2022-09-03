class Solution {
public:
    int trailingZeroes(int n) {
        int c = 0;
        for( long long int i = 5; i<=n ; i*=5 ) {
            c += (n/i) ; 
        }
        return c;
    }
};