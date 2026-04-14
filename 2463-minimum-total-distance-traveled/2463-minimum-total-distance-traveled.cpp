class Solution {
public:
    long long recc(int ri,int fj,vector<int>&robot,vector<int>&fact,vector<vector<long long>>&dp){
        if(ri>=robot.size()) return 0;
        if(fj>=fact.size()) return 1e12;
        if(dp[ri][fj]!=-1) return dp[ri][fj];
        long long take = (long long)abs(fact[fj]-robot[ri]) + recc(ri+1,fj+1,robot,fact,dp);
        long long skip = recc(ri,fj+1,robot,fact,dp);
        return dp[ri][fj]=min(take,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int>fact;
        for(auto &it:factory){
            int limit = it[1];
            int num = it[0];
            for(int i=0;i<limit;i++){
                fact.push_back(num);
            }
        }
        vector<vector<long long>>dp(robot.size(),vector<long long>(fact.size(),-1));
        return recc(0,0,robot,fact,dp);
    }
};