class Solution {
public:
int solve(int i, int j , vector<int> &a,vector<vector<int>> &dp){
    if(i>j)
        return 0;
    if( dp[i][j]!=-1 )
        return dp[i][j];
    int ans = INT_MIN;
    for( int idx=i;idx<=j;idx++) {
        ans = max(ans,a[i-1]*a[idx]*a[j+1] + solve(i,idx-1,a,dp) + solve(idx+1,j,a,dp));
    }
    return dp[i][j]=ans;
}
    
int maxCoins(vector<int>& nums)
{
	// Write your code here.
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(),1);
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    return solve(1,n,nums,dp);
}
};