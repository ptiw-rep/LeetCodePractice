class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto num : nums) 
            mp[num]++;
        vector<vector<int>> bc(nums.size()+1);
        for( auto x : mp ) {
            bc[x.second].push_back(x.first);
        }
        vector<int> res;
        for( int i = nums.size();i>=0 ; i-- ) {
            for( int t : bc[i] ) {
                res.push_back(t);
                k--;
                if( k==0 )
                    return res;
            }
        }
        return res;
    }
};