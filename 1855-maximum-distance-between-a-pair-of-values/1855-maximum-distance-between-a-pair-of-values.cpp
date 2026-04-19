class Solution {
public:
    // int bs(int num,vector<int>&nums){
    //     int id = -1;
    //     int m = nums2.size();
    //     int start = 0;
    //     int end = m-1;
    //     while(start<=end){
    //         int mid = (start+end)/2;
    //         if(nums[mid]>=num){

    //         }
    //     }
    // }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int result = 0;
        for(int i=0;i<n;i++){
            int j = upper_bound(nums2.begin(),nums2.end(),nums1[i],greater<int>())-nums2.begin()-1;
            result = max(result,j-i);
        }
        return result;
    }
};