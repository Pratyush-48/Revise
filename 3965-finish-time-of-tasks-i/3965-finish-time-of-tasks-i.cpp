class Solution {
public:
    long long recc(int node,unordered_map<int,vector<int>>&adj,vector<int>& baseTime){
        if(adj.find(node)==adj.end()){
            return baseTime[node];
        }
        long long earliest = LONG_LONG_MAX;
        long long latest = 0;
        for(auto &it:adj[node]){
            long long child = recc(it,adj,baseTime);
            earliest =  min(earliest,child);
            latest = max(latest,child);
        }
        long long ownduration = (latest-earliest) + baseTime[node];
        long long task_i = (latest+ownduration);
        return task_i;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        unordered_map<int,vector<int>>adj;
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
        }
        return recc(0,adj,baseTime);
    }
};