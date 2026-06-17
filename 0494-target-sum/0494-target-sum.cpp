class Solution {
public:
    int n;
    int recc(int idx,vector<int>&nums,int target,int curr,unordered_map<string,int>&dp){
        if(idx>=n){
            if(curr==target) return 1;
            return 0;
        }
        string key = to_string(idx) + '#' + to_string(curr);
        if(dp.find(key)!=dp.end()) return dp[key];
        int pos = recc(idx+1,nums,target,curr+nums[idx],dp);
        int neg = recc(idx+1,nums,target,curr-nums[idx],dp);
        return dp[key] = pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int>dp;
        n = nums.size();
        return recc(0,nums,target,0,dp);
    }
};