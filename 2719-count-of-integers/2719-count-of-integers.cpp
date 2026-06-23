class Solution {
public:
    long mod = 1e9 + 7;
    long dp[23][2][2][401];
    long recc(int idx,int tight,int leading_zeros,string &num,int sum,int allowed,int allowed2){
        if(sum>allowed) return 0;
        if(idx>=num.length()){
            if(sum>=allowed2) return 1;
            return 0;
        }
        if(dp[idx][tight][leading_zeros][sum]!=-1) return dp[idx][tight][leading_zeros][sum];
        int limit = tight?num[idx]-'0':9;
        long result = 0;
        for(int i=0;i<=limit;i++){
            int next_tight = tight && (i==limit);
            int next_leading_zeros = leading_zeros && (i==0);
            result = (result+recc(idx+1,next_tight,next_leading_zeros,num,sum+i,allowed,allowed2)%mod)%mod;
        }
        return dp[idx][tight][leading_zeros][sum] = result%mod;
    }
    string subtractOne(string num) {
    int n = num.length();
    for (int i = n - 1; i >= 0; i--) {
        if (num[i] > '0') {
            num[i] = num[i] - 1;
            break;
        } else {
            num[i] = '9';
        }
    }
    if (num[0] == '0' && num.length() > 1) {
        num.erase(0, 1); 
    }
    return num;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        long maxi = recc(0,true,true,num2,0,max_sum,min_sum);
        string numm1 = subtractOne(num1);
        memset(dp,-1,sizeof(dp));
        long mini = recc(0,true,true,numm1,0,max_sum,min_sum);
        return (maxi-mini+mod)%mod;
    }
};