class Solution {
public:
// int solve(int i, int j , vector<int> &a,vector<vector<int>> &dp){
//     if(i>j)
//         return 0;
//     if( dp[i][j]!=-1 )
//         return dp[i][j];
//     int ans = INT_MIN;
//     for( int idx=i;idx<=j;idx++) {
//         ans = max(ans,a[i-1]*a[idx]*a[j+1] + solve(i,idx-1,a,dp) + solve(idx+1,j,a,dp));
//     }
//     return dp[i][j]=ans;
// }
    
// int maxCoins(vector<int>& nums)
// {
// 	// Write your code here.
//     int n = nums.size();
//     nums.push_back(1);
//     nums.insert(nums.begin(),1);
//     vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
//     return solve(1,n,nums,dp);
// }
    int maxCoins(vector<int>& nums)
    {
        // Write your code here.
        int i,j,n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int> (n+2,0));
        for( i=n;i>0;i--){
            for(j=1;j<=n;j++){
                if( i>j )
                    continue;
                int ans = INT_MIN;
                for( int idx=i;idx<=j;idx++) {
                    ans = max(ans,nums[i-1]*nums[idx]*nums[j+1] + dp[i][idx-1] + dp[idx+1][j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n];
    }
};