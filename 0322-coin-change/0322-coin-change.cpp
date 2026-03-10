class Solution {
public:
    int calc(vector<int>& coins,int amount,int idx,vector<vector<int>>&dp){
        if(amount==0){
            return 0;
        }
        if(amount<0 || idx<0) return 1e8;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int take = 1e8;
        if(coins[idx]<=amount){
            take = 1+calc(coins,amount-coins[idx],idx,dp);
        }
        int not_take = 1e8;
        not_take = calc(coins,amount,idx-1,dp);
        return dp[idx][amount]=min(take,not_take);

    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int result = calc(coins,amount,n-1,dp);
        return result==1e8?-1:result;
    }
};