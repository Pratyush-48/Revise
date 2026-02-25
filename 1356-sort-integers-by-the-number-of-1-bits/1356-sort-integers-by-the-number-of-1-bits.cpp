class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>result;
        vector<pair<int,int>>temp;
        for(auto &it:arr){
            int num = it;
            int bits = 0;
            while(num){
                bits += num%2;
                num /= 2;
            }
            temp.push_back({bits,it});
        }
        sort(temp.begin(),temp.end(),[](pair<int,int>&a,pair<int,int>&b){
            if(a.first==b.first){
                return a.second < b.second;
            }
            return a.first<b.first;
        });
        for(auto &it:temp){
            result.push_back(it.second);
        }
        return result;
    }
};