class Solution {
public:
    typedef pair<int,int> p;
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int all_zero = 0;
        int all_one = 0;
        vector<int>pref_zero;
        vector<int>pref_one;
        for(int i=0;i<n;i++){
            pref_zero.push_back(all_one);
            pref_one.push_back(all_zero);
            if(s[i]=='0'){
                all_one++;
            }
            else{
                all_zero++;
            }
        }
        int result = INT_MAX;
        for(int i=0;i<n;i++){
            result = min(result,pref_one[i]+all_one-pref_zero[i]);
        }
        return min({result,all_one,all_zero});
    }
};