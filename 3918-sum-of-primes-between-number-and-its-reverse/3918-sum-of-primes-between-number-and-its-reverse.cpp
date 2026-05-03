class Solution {
public:
    void s(vector<int>&sieve){
        int n = sieve.size();
        for(int i=2;i<n;i++){
            if(sieve[i]==1){
            for(int j=(i+i);j<n;j+=i){
                sieve[j] = -1;
            }
            }
        }
    }
    int sumOfPrimesInRange(int n) {
        int rev_n = 0;
        int num = n;
        while(num){
            int m = num%10;
            rev_n *= 10;
            rev_n += m;
            num /= 10;
        }
        int start = min(n,rev_n);
        int end = max(n,rev_n);
        vector<int>sieve(end+1,1);
        s(sieve);
        long result = 0;
        for(int i=start;i<=end;i++){
            if(i==1) continue;
            if(sieve[i]==1) result+=(long)i;
        }
        return result;
    }
};