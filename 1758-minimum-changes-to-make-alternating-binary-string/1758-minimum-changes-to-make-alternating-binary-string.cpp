class Solution {
public:
    int minOperations(string s) {
        int mini = INT_MAX;
        int zero = 0;
        int curr =0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]!=('0'+curr)) zero++;
            curr = (1+curr)%2;
        }
        mini = min(mini,zero);
        zero = 0;
        curr = 1;
        for(int i=0;i<n;i++){
            if(s[i]!=('0'+curr)) zero++;
            curr = (1+curr)%2;
        }
        mini = min(mini,zero);
        return mini;
    }
};