class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result = 0;
        int start = 0;
        for(auto &it:gain){
            start += it;
            result = max(result,start);
        }
        return result;
    }
};