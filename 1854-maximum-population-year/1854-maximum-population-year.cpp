class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>>log;
        int n = logs.size();
        for(int i=0;i<n;i++){
            log.push_back({logs[i][0],1});
            log.push_back({logs[i][1],-1});
        }
        sort(log.begin(),log.end());
        for(int i=1;i<log.size();i++){
            log[i].second = log[i].second+log[i-1].second;
        }
        int result = log[0].first;
        int counter = 1;
        int year = log[0].first;
        int max_count = 1;
        for(int i=1;i<log.size();i++){
            if(year==log[i].first){
                counter = log[i].second;
            }
            else{
                if(max_count<counter){
                    result = year;
                    max_count = counter;
                }
                counter = log[i].second;
                year = log[i].first;
            }
        }
        if(max_count<counter){
            result = year;
            max_count = counter;
        }
        return result;
    }
};