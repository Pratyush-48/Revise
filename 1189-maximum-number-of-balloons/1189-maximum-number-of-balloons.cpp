class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string fin = "balloon";
        vector<int>freq(26,0);
        for(auto &it:text){
            freq[it-'a']++;
        }
        int result = INT_MAX;
        for(auto &it:fin){
            if(it=='o' || it=='l'){
                result = min(result,freq[it-'a']/2);
            }
            else
            result = min(result,freq[it-'a']);
        }
        return result;
    }
};