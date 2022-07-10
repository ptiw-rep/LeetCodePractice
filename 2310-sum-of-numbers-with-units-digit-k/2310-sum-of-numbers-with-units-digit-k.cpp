class Solution {
public:
    int f(vector<int>& nums,int sum,int i,vector<vector<int>> &dp){
        if(sum==0)return 0;
        if(i==0){
            if(nums[0]!=0 && sum%nums[0]==0){
                return sum/nums[0];
            }
            return 1e9;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int left=INT_MAX,right=INT_MAX;
        left=f(nums,sum,i-1,dp);
        if(nums[i]<=sum)
            right = f(nums,sum-nums[i],i,dp)+1;
        return dp[i][sum] = min(left,right);
    }
    int minimumNumbers(int num, int k) {
        vector<int> v;
        
        if(num==0 && k==0)return 0;
        if(num==0){
            return 0;
        }
        if( num<k){
            return -1;
        }
        while(k<=num){
            v.push_back(k);
            k+=10;
        }
        int n = v.size();
        vector<vector<int>> dp(n+1,vector<int>(num+1,-1));
        int res=f(v,num,v.size()-1,dp);
        return res==1e9?-1:res;
    }
};