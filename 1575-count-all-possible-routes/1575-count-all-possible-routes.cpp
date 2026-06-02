class Solution {
public:
    int n;
    int mod = 1e9 + 7;
    int dp[101][201];
    int recc(int idx,int fin,int fuel,vector<int>&loc){
        if(fuel<0) return 0;
        if(dp[idx][fuel]!=-1) return dp[idx][fuel];
        int result = idx==fin?1:0;
        for(int j=0;j<n;j++){
            if(idx==j) continue;
            result = (result+recc(j,fin,fuel-abs(loc[idx]-loc[j]),loc)%mod)%mod;
        } 
        return dp[idx][fuel] = result;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        n = locations.size();
        int res = recc(start,finish,fuel,locations)%mod;
        return res;
    }
};