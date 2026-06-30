class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        long long result = 0;
        vector<int>store = {0,0,0};
        while(j<n){
            char ch = s[j];
            store[ch-'a']++;
            while(i<n && store[0]!=0 && store[1]!=0 && store[2]!=0){
                result += (n-j);
                store[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return result;
    }
};