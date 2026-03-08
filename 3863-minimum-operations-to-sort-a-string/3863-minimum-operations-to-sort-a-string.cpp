class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        bool done = true;
        for(int i=1;i<n;i++){
            if(s[i]<s[i-1]){
                done = false;
                break;
            }
        }
        if(done) return 0;
        if(n==2) return -1;
        char mini = s[0];
        char maxi = s[0];
        for(auto &it:s){
            mini = min(mini,it);
            maxi = max(maxi,it);
        }
        if(s[0]==mini || s[n-1]==maxi){
            return 1;
        }
        int mini_c = 0;
        int maxi_c = 0;
        for(auto &it:s){
            if(it==mini) mini_c++;
            if(it==maxi) maxi_c++;
        }
        if(s[0]==maxi && s[n-1]==mini && mini_c==1 && maxi_c==1){
            return 3;
        }
        return 2;
    }
};