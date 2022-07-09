class Solution {
public:
    int m = 1e9 + 7;
    int countHousePlacements(int n) {
        // Dono side bharne ka sense nh kuch, kyuki filling independent hai
        // Ek side ka result nikal ke doosre side se cartesian product
        // TC likho fibo jaisa banega f(n) = f(n-1) + f(n-2)
        long long int tempAns = 0;
        if( n==1 )
            tempAns = 2;
        int f = 1, s = 2;
        for( int i=2;i<=n;i++ ) {
            tempAns = (f + s) % m;
            f = s;
            s = tempAns;
        }
        return (tempAns*tempAns)%m;
    }
};