class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int length = 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                length = i;
            }
        }
        return length;
    }
};