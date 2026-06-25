class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=i;j<n;j++){
                if(nums[j]==target) count++;
                int l = j-i+1;
                if(count > floor(l/2.0)) result++;
            }
        }
        return result;
    }
};