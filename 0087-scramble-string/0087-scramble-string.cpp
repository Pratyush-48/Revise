class Solution {
public:
    bool recc(string s1,string s2,unordered_map<string,bool>&dp){
        if(s1==s2) return true;
        if(s1.length() != s2.length())
            return false;
        string key = s1 + "#" + s2;
        if(dp.find(key)!=dp.end()){
            return dp[key];
        }
        int n = s1.length();
        for(int i=1;i<n;i++){
            bool swapped = recc(s1.substr(i,n-i),s2.substr(0,n-i),dp) && recc(s1.substr(0,i),s2.substr(n-i,i),dp);
            if(swapped) return true;
            bool not_swapped = recc(s1.substr(i,n-i),s2.substr(i,n-i),dp) && recc(s1.substr(0,i),s2.substr(0,i),dp);
            if(not_swapped) return true;
        }
        return dp[key]=false;
    }
    bool isScramble(string s1, string s2) {
        // basicaly we need to check by swapping or not swapping
        unordered_map<string,bool>dp;
        return recc(s1,s2,dp);
    }
};