class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        unordered_map<string,long>mp;
        for(int i=0;i<n;i++){
            if(i+k > n) break;
            mp[s.substr(i,k)]++;
        }
        long long num = pow(2,k);
        return mp.size()>=num;
    }
};