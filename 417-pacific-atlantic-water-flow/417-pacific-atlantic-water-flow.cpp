class Solution {
public:
   
    void dfs(vector<vector<int>>&ans,int &flag1,int &flag2,vector<vector<int>>&arr,int i,int j,int m,int n,int prev, vector<vector<int>> &vis)
    {   
        if(arr[i][j]>prev)
        {
            return;
        }
        if(i==0||j==0)
        {
            flag1=1;
        }
        if(i==m-1||j==n-1)
        {
            flag2=1;
        }
        if(flag1==1 && flag2==1)
        {
            return;
        }
        if(i+1<m && vis[i+1][j]==0 )
        {
            vis[i][j]=1;
            dfs(ans,flag1,flag2,arr,i+1,j,m,n,arr[i][j],vis);
            vis[i][j]=0;
        }
         if(i-1>=0 && vis[i-1][j]==0)
        {
             vis[i][j]=1;
            dfs(ans,flag1,flag2,arr,i-1,j,m,n,arr[i][j],vis);
             vis[i][j]=0;
        }
         if(j+1<n && vis[i][j+1]==0)
        {
             vis[i][j]=1;
            dfs(ans,flag1,flag2,arr,i,j+1,m,n,arr[i][j],vis);
             vis[i][j]=0;
        }
         if(j-1>=0 && vis[i][j-1]==0)
        {
             vis[i][j]=1;
            dfs(ans,flag1,flag2,arr,i,j-1,m,n,arr[i][j],vis);
             vis[i][j]=0;
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int flag1=0,flag2=0;
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   
                flag1=0,flag2=0;
                dfs(ans,flag1,flag2,heights,i,j,m,n,1e6,vis);
                if(flag1==1 && flag2==1)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};