class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int result = INT_MAX;
        int n = nums.size();
        for(int i=1;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                result = min(result,nums[0]+nums[i]+nums[j]);
            }
        }
        return result;
    }
};