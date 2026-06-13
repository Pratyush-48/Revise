class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result="";
        for(auto &it:words){
            int sum = 0;
            for(auto &it2:it){
                sum += weights[it2-'a'];
            }
            sum = sum%26;
            result += ('z'-sum);
        }
        return result;
    }
};