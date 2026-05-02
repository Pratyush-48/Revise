class Solution {
public:
    int bs(vector<vector<int>>&jobs,int time){
        int n = jobs.size();
        int left = 0;
        int right = n-1;
        int result = -1;
        while(left<=right){
            int mid = (left+right)/2;
            if(jobs[mid][0]>=time){
                result = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return result==-1?n:result;
    }
    long recc(int idx,vector<vector<int>>&jobs,int n,vector<long>&dp){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        long dont_take = recc(idx+1,jobs,n,dp);
        int n_idx = bs(jobs,jobs[idx][1]);
        long take = (long)jobs[idx][2]+recc(n_idx,jobs,n,dp);
        return dp[idx]=max(take,dont_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>jobs;
        int n = startTime.size();
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[2]>b[2];
            }
            return a[0]<b[0];
        });
        vector<long>dp(n+1,-1);
        return recc(0,jobs,n,dp);
    }
};