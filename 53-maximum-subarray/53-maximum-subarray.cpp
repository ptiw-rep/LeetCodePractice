class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minSum = 0, currSum = 0, mxSumSubArr = INT_MIN;
        for( int x : nums ) {
            currSum+= x;
            mxSumSubArr = max(mxSumSubArr, currSum - minSum );
            minSum = min( minSum, currSum);
        }
        return mxSumSubArr;
    }
};