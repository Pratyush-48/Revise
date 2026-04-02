class Solution {
public:
    int dp[501][501][3];
    int recc(int i,int j,int m,int n,vector<vector<int>>&coins,int k){
        if(i==m-1 && j==n-1){
            if(k>0 && coins[i][j]<0) return 0;
            return coins[i][j];
        }
        if(i>=m || j>=n) return -1e9;
        if(dp[i][j][k]!=-1e9) return dp[i][j][k];
        int coinss = INT_MIN;
        if(k>0){
            int dont = recc(i+1,j,m,n,coins,k-1);
            coinss = max(coinss,dont);
            dont = recc(i,j+1,m,n,coins,k-1);
            coinss = max(coinss,dont);
        }
        int take = coins[i][j] + recc(i+1,j,m,n,coins,k);
        coinss = max(coinss,take);
        take = coins[i][j] + recc(i,j+1,m,n,coins,k);
        coinss = max(coinss,take);
        return dp[i][j][k]=coinss;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
       for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int l = 0; l < 3; l++) {
                    dp[i][j][l] = -1e9;
                }
            }
        }
        return recc(0,0,m,n,coins,2);
    }
};