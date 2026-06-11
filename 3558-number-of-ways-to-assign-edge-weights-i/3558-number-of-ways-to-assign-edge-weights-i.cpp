class Solution {
public:
    int m;
    typedef long long ll;
    ll myPow(ll x, ll n) {
    if(n<0) return 0;
    if(n == 0)
        return 1;
    if(x == 1)
        return 1;
    
    ll result = myPow(x, n/2);
    result = (result%m * result%m)%m;
    if(n%2 != 0)
        result = (result%m * x%m)%m;
    return result;
}
    int find_max_depth(unordered_map<int,vector<int>>&adj){
        queue<int>q;
        unordered_set<int>st;
        int level = 0;
        int node = -1;
        q.push(1);
        st.insert(1);
        while(!q.empty()){
            int s = q.size();
            while(s--){
                node = q.front();
                q.pop();
                for(auto &child:adj[node]){
                    if(st.find(child)==st.end()){
                    q.push(child);
                    st.insert(child);
                    }
                }
            }
            level++;
        }
        return level-1;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto &ed:edges){
            int u = ed[0];
            int v = ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        m = 1e9 + 7;
        long d = find_max_depth(adj);
        ll result = myPow(2,d-1);
        return result;

    }
};