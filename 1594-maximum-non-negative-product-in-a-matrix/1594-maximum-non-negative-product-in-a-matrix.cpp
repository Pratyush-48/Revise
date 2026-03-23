class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1e9+7;
        vector<vector<pair<long long ,long long>>>dp(m,vector<pair<long long,long long>>(n));
        dp[0][0]={grid[0][0],grid[0][0]};
        for(int i=1;i<m;i++){
            dp[i][0].first=max(dp[i-1][0].first*grid[i][0],dp[i-1][0].second*grid[i][0]);
            dp[i][0].second=min(dp[i-1][0].first*grid[i][0],dp[i-1][0].second*grid[i][0]);
        }
        for(int i=1;i<n;i++){
            dp[0][i].first=max(dp[0][i-1].first*grid[0][i],dp[0][i-1].second*grid[0][i]);
            dp[0][i].second=min(dp[0][i-1].first*grid[0][i],dp[0][i-1].second*grid[0][i]);
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j].first=max({dp[i-1][j].first*grid[i][j],dp[i-1][j].second*grid[i][j],dp[i][j-1].first*grid[i][j],dp[i][j-1].second*grid[i][j]});
                dp[i][j].second=min({dp[i-1][j].first*grid[i][j],dp[i-1][j].second*grid[i][j],dp[i][j-1].first*grid[i][j],dp[i][j-1].second*grid[i][j]});
            }
        }
        if(((dp[m-1][n-1].first)%mod < 0) && ((dp[m-1][n-1].second)%mod < 0)){
            return -1;
        }
        return (max(dp[m-1][n-1].first%mod , dp[m-1][n-1].second%mod)%mod)%mod;
    }
};