class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // im using line sweep algorithm
        vector<vector<int>>trip;
        for(auto &it:trips){
            int pa = it[0];
            int start  = it[1];
            int end = it[2];
            trip.push_back({start,pa});
            trip.push_back({end,-1*pa});
        }
        sort(trip.begin(),trip.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });
        int prefix = 0;
        for(auto &it:trip){
            prefix += it[1];
            if(prefix>capacity) return false;
        }
        return true;
    }
};