class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,n=height.size();
        int j=n-1,ans=0;
        while(i<=j)
        {
            ans=max((j-i)*min(height[i],height[j]),ans);
            if(height[i]<height[j])
            {
                ++i;
            }
            else{
                --j;
            }
        }
        return ans;
    }
};