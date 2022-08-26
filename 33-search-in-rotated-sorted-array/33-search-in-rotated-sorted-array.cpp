class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while( low<=high ) {
            int mid = low + (high-low)/2;
            if( nums[mid]==target )
                return mid;
            // check for sorted part
            if( nums[low]<=nums[mid] ) {
                // check target exists here
                if( nums[low]<=target && nums[mid]>=target ) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            else {
                if( nums[mid]<=target && nums[high]>=target ) {
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int low=0,high=nums.size()-1;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(nums[mid]==target)
//                 return mid;
//             // check which half is sorted
//             if(nums[low]<=nums[mid]){
//                 if(nums[low]<=target && target<=nums[mid])
//                     high=mid-1;
//                 else
//                     low=mid+1;
//             }
//             else{
//                 if(nums[mid]<=target && target<=nums[high])
//                     low=mid+1;
//                 else
//                     high=mid-1;
//             }
//         }
//         return -1;
//     }
// };