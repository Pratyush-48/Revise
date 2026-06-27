class Solution {
public:
    long dp[20002];
    int n;
    long recc(int idx,vector<int>&nums){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        long take = 0;
        long dont_take = 0;
        int new_idx = upper_bound(nums.begin(),nums.end(),nums[idx]+1)-nums.begin();
        long l = upper_bound(nums.begin(),nums.end(),nums[idx])-nums.begin();
        take = ((l-idx)*nums[idx])+recc(new_idx,nums);
        dont_take = recc(l,nums);
        return dp[idx] = max(take,dont_take);
    }
    int deleteAndEarn(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        return recc(0,nums);
    }
};