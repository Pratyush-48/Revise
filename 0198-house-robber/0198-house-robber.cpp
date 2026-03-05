class Solution {
public:
    // lets memoize
    int t[101];
    int solve(int idx,vector<int>&nums,int n){
        if(idx>=n) return 0;
        if(t[idx] != -1) return t[idx];
        //take
        int take = nums[idx]+solve(idx+2,nums,n);
        //skip
        int skip = solve(idx+1,nums,n);

        return  t[idx] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // remember
        memset(t,-1,sizeof(t));
        return solve(0,nums,n);
    }
};