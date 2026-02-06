class Solution {
public:
    int bs(int i,vector<int>&nums,int k){
        int left = i;
        int n = nums.size();
        int right = nums.size()-1;
        long long num = (long long)nums[i]*k;
        int result = i;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]<=num){
                result = mid;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return result;
    }
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int result = INT_MAX;
        for(int i=0;i<n;i++){
            result = min(result,n-bs(i,nums,k)+i-1);
        }
        return result;
    }
};