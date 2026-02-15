class Solution {
public:
    long long fn(int i,vector<int>& nums, vector<int>& colors,vector<long long> &dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        long long skip = fn(i+1, nums, colors, dp);
        long long take = nums[i];

        if(i+1 < nums.size()){
            if(colors[i] == colors[i+1]){
                take += fn(i+2, nums, colors, dp);
            }
            else{
                take += fn(i+1, nums, colors, dp);
            }
        }

        return dp[i] = max(take, skip);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<long long> dp(nums.size(),-1);
        return fn(0,nums,colors,dp);
    }
};