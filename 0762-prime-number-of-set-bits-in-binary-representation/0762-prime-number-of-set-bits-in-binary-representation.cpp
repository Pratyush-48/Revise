class Solution {
public:
    void sieve(vector<bool>&is_prime){
        int n = is_prime.size();
        for(int i=2;i<n;i++){
            if(is_prime[i]==1){
                for(int j=2*i;j<n;j+=i){
                    is_prime[j] = 0;
                }
            }
        }
    }
    int countPrimeSetBits(int left, int right) {
        vector<bool>is_prime(33,1);
        is_prime[0] = 0;
        is_prime[1] = 0;
        sieve(is_prime);
        int result = 0;
        for(int i=left;i<=right;i++){
            int num = i;
            int bit = 0;
            while(num){
                bit += (num%2);
                num /= 2;
            }
            if(is_prime[bit]==1) result++;
        }
        return result;
    }
};