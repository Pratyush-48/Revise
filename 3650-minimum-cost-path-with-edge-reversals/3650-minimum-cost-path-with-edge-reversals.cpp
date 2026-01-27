class Solution {
public:
    typedef pair<int,int> p;
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<p>>adj;
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        vector<int>dist(n,INT_MAX);
        priority_queue<p,vector<p>,greater<p>>mini;
        mini.push({0,0});
        while(!mini.empty()){
            int d = mini.top().first;
            int u  = mini.top().second;
            if(u==n-1) return dist[n-1];
            mini.pop();
            for(auto&it:adj[u]){
                int v = it.first;
                int w = it.second;
                if((d+w)<dist[v]){
                    dist[v] = d+w;
                    mini.push({d+w,v});
                }
            }
        }
        return -1;
    }
};