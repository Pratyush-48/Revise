class Solution {
public:
    char processStr(string s, long long k) {
        // first find out L in one iteration
        long long l = 0;
        for(auto  &it:s){
            if(it=='*'){
                if(l>0){
                    l--;
                }
            }
            else if(it=='#'){
                l *= 2;
            }
            else if(it=='%'){
                continue;
            }
            else{
                l++;
            }
        }
        if(k>=l) return '.';
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='*'){
                l++;
            }
            else if(s[i]=='#'){
                l /= 2;
                if(k>=l)
                k -= l;
            }
            else if(s[i]=='%'){
                k = l-k-1;
            }
            else{
                l--;
            }
            if(l==k){
            return s[i];
            }
        }
        return '.';
    }
};