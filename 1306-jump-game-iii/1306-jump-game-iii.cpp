class Solution {
public:
    int n;
    bool traverse(int idx,vector<int>&arr,vector<int>&dp){
        if(idx<0 || idx>=n) return false;
        if(arr[idx]==0) return true;
        if(dp[idx]!=-1) return dp[idx];
        dp[idx] = 0;
        bool back = traverse(idx-arr[idx],arr,dp);
        bool front = traverse(idx+arr[idx],arr,dp);
        return dp[idx] = (back|front);
    }
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vector<int>dp(n,-1);
        return traverse(start,arr,dp);
    }
};