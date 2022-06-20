class Solution {
public:
    // Brute : Try all pairs O(n^2)
    // O(N) work on remainder
    int numPairsDivisibleBy60(vector<int>& time) {
        int pairs = 0;
        vector<int> rem (60,0); // vector to store count for remainder 
        for( int x : time ) {
            x = x%60;
            if( x==0 )  {
                pairs+= rem[0];
            }
            else {
                pairs+= rem[60-x];
            }
            rem[x]++;
        }
        return pairs;
    }
};