class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0;
        int j = 0;
        unordered_map<char,pair<int,int>>mp;
        mp['U'] = {-1,0};
        mp['L'] = {0,-1};
        mp['D'] = {1,0};
        mp['R'] = {0,1};
        for(auto &it:moves){
            i += mp[it].first;
            j += mp[it].second;
        } 
        return i==0 && j==0;

    }
};