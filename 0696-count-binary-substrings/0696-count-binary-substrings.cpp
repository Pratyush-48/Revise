class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int i = 0;
        long result = 0;
        int prev = 0;
        while(i<n){
            int left = i;
            if(s[i]=='0'){
                while(i<n && s[i]=='0'){
                    i++;
                }
            }
            else{
                while(i<n && s[i]=='1'){
                    i++;
                }
            }
            result += min(prev,i-left);
            prev = i-left;
        }
        return result;
    }
};