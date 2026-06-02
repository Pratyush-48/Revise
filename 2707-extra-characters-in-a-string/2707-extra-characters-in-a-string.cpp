class Solution {
public:
    unordered_set<string>st;
    int n;
    int dp[51];
    int recc(int idx,string &s){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        if(st.find(s.substr(idx))!=st.end()) return dp[idx]=0;
        int result = INT_MAX;
        for(int l = 1;l<=n;l++){
            string temp = s.substr(idx,l);
            if(st.find(temp)!=st.end()){
                result = min(result,recc(idx+l,s));
            }
            else{
                result = min(result,l+recc(idx+l,s));
            }
        }
        return dp[idx]=result;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto &it:dictionary){
            st.insert(it);
        }
        n = s.length();
        memset(dp,-1,sizeof(dp));
        return recc(0,s);
    }
};