class Solution {
public:
   bool bff(unordered_map<int,vector<vector<int>>>&adj, int n, int s, int t, int k, int th){
    // Track the maximum 'k' (skips) we had when arriving at each node.
    // Initialize to -1 (meaning unvisited)
    vector<int> max_k(n, -1);
    max_k[s] = k;
    
    queue<vector<int>> q;
    q.push({s, k});
    
    while(!q.empty()){
        int node = q.front()[0];
        int h = q.front()[1];
        q.pop();
        
        if(node == t) return true;
        
        for(auto &it : adj[node]){
            int neigh = it[0];
            int wt = it[1];
            
            // Calculate skips remaining after taking this edge
            int new_k = (wt > th) ? h - 1 : h;
            
            if(new_k < 0) continue; // Invalid path, out of skips
            
            // ONLY push to queue if we arrived with MORE skips than any previous time
            if(new_k > max_k[neigh]){
                max_k[neigh] = new_k;
                q.push({neigh, new_k});
            }
        }
    }
    return false;
}
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        unordered_map<int,vector<vector<int>>>adj;
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        long high = 1e12;
        long low = 0;
        long result = LONG_MAX;
        while(low<=high){
            long mid = (high+low)/2;
            if(bff(adj,n,source,target,k,mid)){
                result = min(result,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result==LONG_MAX?-1:result;
    }
};