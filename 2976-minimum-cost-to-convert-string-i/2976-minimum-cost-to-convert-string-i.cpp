class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<vector<long long>>dist(26,vector<long long>(26,1e12));
        for(int i=0;i<n;i++){
            int u = original[i]-'a';
            int v = changed[i]-'a';
            dist[u][v] = min(dist[u][v],(long long)cost[i]);
        }
        for(int via=0;via<26;via++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    dist[i][j] = min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j) dist[i][j] = 0;
                if(dist[i][j]==1e12) dist[i][j] = -1;
            }
        }
        long long result = 0;
        int m = source.length();
        if(m!=target.length()) return -1;
        for(int i=0;i<m;i++){
            int u = source[i]-'a';
            int v = target[i]-'a';
            if(dist[u][v]==-1) return -1;
            result += dist[u][v];
        }
        return result;
    }
};