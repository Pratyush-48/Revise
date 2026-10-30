class node{
    public:
    int v;
    int best;
    int curr_count;
    char last;
    int distance;
    node(int v,int b,int c,char l,int d){
        this->v = v;
        best =b;
        curr_count = c;
        last = l;
        distance = d;
    }
};

struct compare {
    bool operator()(node* a, node* b) {
        return a->distance > b->distance;
    }
};

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int,vector<vector<int>>>adj;
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            //adj[v].push_back({u,w}); 
        }
        
        vector<vector<int>> path(n, vector<int>(k + 1, INT_MAX));
        priority_queue<node*,vector<node*>,compare>pq;
        
        pq.push(new node(0, 0, 1, labels[0], 0));
        path[0][1] = 0;
        
        while(!pq.empty()){
            node* curr = pq.top();
            pq.pop();
            
            int u = curr->v;
            int count = curr->curr_count;
            int d = curr->distance;
            char last_char = curr->last;
            
            if (u == n - 1) {
                return d;
            }
            
            if (d > path[u][count]) {
                delete curr;
                continue;
            }
            
            for(auto &neighbor : adj[u]){
                int next_node = neighbor[0];
                int weight = neighbor[1];
                
                int next_count = 1;
                if (labels[next_node] == last_char) {
                    next_count = count + 1;
                }
                
                if (next_count > k) continue;
                
                if (d + weight < path[next_node][next_count]) {
                    path[next_node][next_count] = d + weight;
                    pq.push(new node(next_node, 0, next_count, labels[next_node], d + weight));
                }
            }
            
            delete curr;
        }
        
        return -1;
    }
};