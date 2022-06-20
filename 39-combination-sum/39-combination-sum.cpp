class Solution {
public:
    void util(int idx, int sum, vector<int> &nums,vector<int> &ds, vector<vector<int>> &ans ) {
        // base case
        if( sum==0 ) {
            ans.push_back(ds);
            return;
        }
        // backtrack
        if( sum<0 || idx==nums.size()) 
            return;
        // do not include ith element
        util(idx+1,sum,nums,ds,ans);
        ds.push_back(nums[idx]);
        util(idx,sum-nums[idx],nums,ds,ans);   
        ds.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        util(0, target, candidates, ds, ans );
        return ans;
    }
};