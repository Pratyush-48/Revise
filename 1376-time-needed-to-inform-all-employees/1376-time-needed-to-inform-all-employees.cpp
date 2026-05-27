class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue<pair<int,int>>q;
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            if(i!=headID){
                adj[manager[i]].push_back(i);
            }
        }
        int time = 0;
        q.push({headID,informTime[headID]});
        while(!q.empty()){
            int p = q.front().first;
            int t = q.front().second;
            time = max(time,t);
            q.pop();
            for(auto &child:adj[p]){
                q.push({child,t+informTime[child]});
            }
        }
        return time;
    }
};