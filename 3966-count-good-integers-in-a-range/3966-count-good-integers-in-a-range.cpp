class Solution {
public:
    long long dp[17][2][2][11];
    long long recc(int pos,int tight,int leading_zero,int prev,int k,int n,vector<int>&digit){
        if(pos>=n) return 1;
        long long result = 0;
        result = dp[pos][tight][leading_zero][prev];
        if(result != -1) return result;
        result = 0;
        int limit = tight?digit[pos]:9;
        for(int i=0;i<=limit;i++){
            if(prev!=10 && abs(prev-i)>k) continue;
            int next_tight = tight && (i==limit);
            int next_leading_zero = leading_zero && (i==0);
            int next_prev = next_leading_zero ? 10 : i;
            result += recc(pos+1,next_tight,next_leading_zero,next_prev,k,n,digit);
        }
        return dp[pos][tight][leading_zero][prev] = result;
    }
    void extract(long long num,vector<int>&n){
        if(num==0){
            n.push_back(0);
            return;
        }
        while(num){
            int d = num%10;
            num /= 10;
            n.push_back(d);
        }
        reverse(n.begin(),n.end());
    }
    long long goodIntegers(long long l, long long r, int k) {
        vector<int>R;
        vector<int>L;
        extract(l-1,L);
        extract(r,R);
        memset(dp,-1,sizeof(dp));
        int n = L.size();
        long long left = recc(0,true,true,10,k,n,L);
        memset(dp,-1,sizeof(dp));
        n = R.size();
        long long right = recc(0,true,true,10,k,n,R);
        return abs(right-left);
    }
};