class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        for( int &x : nums ){
            if( x>0 ){
                s.insert(x);
            }
        }
        for( int i=1;i<INT_MAX;i++ ){
            if(s.find(i)==s.end())
                return i;
        }
        return 0;
    }
};