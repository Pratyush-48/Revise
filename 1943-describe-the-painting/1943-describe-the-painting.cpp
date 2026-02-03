class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    vector<vector<long long>> result;
    vector<vector<long long>> prefix;
    for(auto &it : segments){
        prefix.push_back({(long long)it[0], (long long)it[2]});
        prefix.push_back({(long long)it[1], -1 * (long long)it[2]});
    }
    sort(prefix.begin(), prefix.end());
    int i = 0;
    int j = 0;
    int m = prefix.size();
    long long pref = 0;
    while(i < m) {
        long long current_pos = prefix[i][0];
        while(j < m && prefix[j][0] == current_pos) {
            pref += prefix[j][1];
            j++;
        }
        if(j < m && pref > 0) {
            result.push_back({current_pos, prefix[j][0], pref});
        }
        i = j;
    }
    return result;
}
};