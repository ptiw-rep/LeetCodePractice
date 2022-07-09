/*
Let's write equation for sum,
newsum(num1) = sum(num1[0 to n]) - sum(num1[i to j] ) + sum(num2[i to j] )
newsum(num2) = sum(num2[0 to n]) - sum(num2[i to j] ) + sum(num1[i to j] )

Rearranging with brackets
newsum(num1) = sum(num1[0 to n]) - ( sum(num1[i to j] ) - sum(num2[i to j] ) )
newsum(num2) = sum(num2[0 to n]) + ( sum(num1[i to j] ) - sum(num2[i to j] ) )

Or
newsum(num1) = sum(num1[0 to n]) + ( sum(num2[i to j] ) - sum(num1[i to j] ) )
newsum(num2) = sum(num2[0 to n]) - ( sum(num2[i to j] ) - sum(num1[i to j] )  )

Let k =(sum(num2[i to j]  - sum(num1[i to j] ))
Again
newsum(num1) = sum(num1[0 to n]) + k
newsum(num2) = sum(num2[0 to n]) - k

Now, observe that to maximize newsum(num1) we need to maximize k and to maximize newsum(num2) we need to minimize k.
*/
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int sum1 = accumulate(nums1.begin(),nums1.end(),0), sum2 = accumulate(nums2.begin(),nums2.end(),0) ;
        // for simplycity we make sum1>sum2 and swap the arrays
        if(sum2>sum1) {
            swap(sum1,sum2);
            swap(nums1,nums2);
        }
        int maxEndingHere, minEndingHere, maxSoFar, minSoFar, currEle;
        maxEndingHere=minEndingHere=maxSoFar=minSoFar=nums2[0]-nums1[0];
        for(int i=1;i<n;i++) {
            int curr = nums2[i] - nums1[i];
            minEndingHere+= curr;
            maxEndingHere+= curr;
            // resetting
            if(maxEndingHere < curr)
                maxEndingHere = curr;
            if(minEndingHere > curr)
                minEndingHere = curr;
            maxSoFar = max(maxSoFar,maxEndingHere);
            minSoFar = min(minSoFar,minEndingHere);
        }
        return max(sum1+ maxSoFar,sum2-minSoFar);
    }
};