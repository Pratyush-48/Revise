class Solution {
public:
    int find(vector<vector<int>>&a,vector<vector<int>>&b){
        int min_time_a = INT_MAX;
        int res = INT_MAX;
        for(auto &it:a){
            min_time_a = min(min_time_a,it[0]+it[1]);
        }
        for(auto &it:b){
            res = min(max(min_time_a,it[0])+it[1],res);
        }
        return res;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<vector<int>>land;
        vector<vector<int>>water;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        for(int i=0;i<n;i++){
            land.push_back({landStartTime[i],landDuration[i]});
        }
        for(int i=0;i<m;i++){
            water.push_back({waterStartTime[i],waterDuration[i]});
        }
        int res_1 = find(land,water);
        int res_2 = find(water,land);
        return min(res_1,res_2);
    }
};