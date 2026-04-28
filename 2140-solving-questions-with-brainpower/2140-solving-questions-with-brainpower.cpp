class Solution {
public:
    int n;
    long long recc(int idx,vector<vector<int>>&q,vector<long long>&dp){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        long long take = q[idx][0] + recc(idx+q[idx][1]+1,q,dp);
        long long nott = recc(idx+1,q,dp);
        return dp[idx]=max(take,nott);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        vector<long long>dp(n,-1);
        return recc(0,questions,dp);
    }
};