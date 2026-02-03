class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        if(nums[i]<=nums[i-1]){
            return false;
        }
        while(i<n && nums[i]>nums[i-1]){
            i++;
        }
        if(i>=n || nums[i]==nums[i-1]) return false;

        while(i<n && nums[i]<nums[i-1]){
            i++;
        }
        if(i>=n || nums[i]==nums[i-1]) return false;
        while(i<n && nums[i]>nums[i-1]){
            i++;
        }
        return i>=n;
    }  

};