class Solution {
public:
    unordered_map<string, unordered_map<string, long long>> dijkstraMemo;
    long long dijkstra(string &source,string &target,unordered_map<string,vector<pair<string,int>>>&adj){
        if(dijkstraMemo[source].count(target)) return dijkstraMemo[source][target];
        priority_queue<pair<long long,string>,vector<pair<long long,string>>,greater<pair<long long,string>>>mini;
        mini.push({0,source});
        unordered_map<string,long long>cost;
        while(!mini.empty()){
            string tar = mini.top().second;
            long long res = mini.top().first;
            mini.pop();
            if(target==tar) return dijkstraMemo[source][target]= res;
            for(auto&it:adj[tar]){
                if(cost.find(it.first)==cost.end()){
                    mini.push({res+it.second,it.first});
                    cost[it.first] = it.second+res;
                }
                else{
                    long long s_p = cost[it.first];
                    if(s_p > res+it.second){
                        cost[it.first] = res+it.second;
                        mini.push({res+it.second,it.first});
                    }
                }
            }
        }
        return dijkstraMemo[source][target]=-1;
    }
    long long DP[1001];
    long long dp(int idx,string &source,string &target,set<int>&siz,int n,unordered_map<string,vector<pair<string,int>>>&adj,bool &flag){
        if(idx>=n) return 0;
        if(DP[idx]!=-1) return DP[idx];
        long long result = 1e12;
        if(source[idx]==target[idx]){
            result = dp(idx+1,source,target,siz,n,adj,flag);
        }
        for(auto &len:siz){
            if(idx+len > n) break;
            string sc = source.substr(idx,len);
            string tc = target.substr(idx,len);
            long long cost = dijkstra(sc,tc,adj);
            if(cost==-1) continue;
            result = min(result,cost+dp(idx+len,source,target,siz,n,adj,flag));
        }
        return DP[idx]=result;
    }
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        set<int>siz;
        unordered_map<string,vector<pair<string,int>>>adj;
        int n = original.size();
        for(int i=0;i<n;i++){
            adj[original[i]].push_back({changed[i],cost[i]});
            siz.insert(original[i].length());
            siz.insert(changed[i].length());
        }
        memset(DP,-1,sizeof(DP));
        bool flag = true;
        long long result = dp(0,source,target,siz,source.length(),adj,flag);
        if(result>=1e12) return -1;
        return result;
    }
};