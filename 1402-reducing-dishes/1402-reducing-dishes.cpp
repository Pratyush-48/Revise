class Solution {
public:
    int n;
    long long recc(int idx,long long time,vector<int>&s,vector<vector<long long>>&dp){
        if(idx>=n) return 0;
        if(dp[idx][time]!=-1) return dp[idx][time];
        long long take = time*s[idx] + recc(idx+1,time+1,s,dp);
        long long dont_take = recc(idx+1,time,s,dp);
        return dp[idx][time]=max(take,dont_take);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
       sort(satisfaction.begin(),satisfaction.end()); 
       vector<vector<long long>>dp(n,vector<long long>(n+2,-1));
       return max(0LL,recc(0,1,satisfaction,dp));
    }
};