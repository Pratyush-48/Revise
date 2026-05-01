class Solution {
public:
    long recc(int idx,int k,vector<vector<int>>&piles,vector<vector<long>>&dp){
        if(k==0) return 0;
        if(idx>=piles.size()) return -1e9;
        if(dp[idx][k]!=-1) return dp[idx][k];
        long dont_take = recc(idx+1,k,piles,dp);
        long take = 0;
        long sum = 0;
        int m = piles[idx].size();
        m = min(m,k);
        for(int i=1;i<=m;i++){
            sum += piles[idx][i-1];
            take = max(take,sum+recc(idx+1,k-i,piles,dp));
        }
        return dp[idx][k]=max(take,dont_take);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<long>>dp(n+1,vector<long>(k+1,-1));
        return recc(0,k,piles,dp);
    }
};