class Solution {
public:
    void bfs(int start,unordered_map<int,vector<int>>&adj,vector<int>&dist,int n){
        queue<int>q;
        vector<int>visited(n,0);
        q.push(start);
        visited[start] = 1;
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();
                dist[node] = level;
                for(auto &it:adj[node]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = true;
                    }
                }
            }
            level++;
        }
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        unordered_map<int,vector<int>>adj;
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dist_x(n,0);
        vector<int>dist_y(n,0);
        vector<int>dist_z(n,0);
        bfs(x,adj,dist_x,n);
        bfs(y,adj,dist_y,n);
        bfs(z,adj,dist_z,n);
        int result = 0;
        for(int i=0;i<n;i++){
            vector<int>dist = {dist_x[i],dist_y[i],dist_z[i]};
            sort(dist.begin(),dist.end());
            if((long long)dist[0]*dist[0] + (long long)dist[1]*dist[1] == (long long)dist[2]*dist[2]){
                result++;
            }
        }
        return result;
        
    }
};