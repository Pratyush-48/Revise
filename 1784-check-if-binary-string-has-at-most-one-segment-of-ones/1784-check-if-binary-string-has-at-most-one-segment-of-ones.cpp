class Solution {
public:
    bool checkOnesSegment(string s) {
        bool ones = false;
        int n = s.length();
        int i = 0;
        while(i<n){
            if(s[i]=='1'){
                if(ones) return false;
                while(i<n && s[i]=='1') i++;
                ones = true;
            }
            i++;
        }
        return true;
    }
};