class Solution {
public:
    int bs(int num,vector<int>&nums){
        int id = -1;
        int m = nums.size();
        int start = 0;
        int end = m-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]>=num){
                id = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return id;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int result = 0;
        for(int i=0;i<n;i++){
            int j = bs(nums1[i],nums2);
            result = max(result,j-i);
        }
        return result;
    }
};