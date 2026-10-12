class Solution {
public:
    using ll = long long;
    int maxSum(vector<int>& nums, int k) {
        ll mod = 1e9 + 7;
        vector<int>freq(33,0);
        int idx = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int num = nums[i];
            int idx = 0;
            while(num){
                int val = num&1;
                num >>= 1;
                freq[idx]+=val;
                idx++;
            }
        }
        ll result = 0;
        while(k--){
            bool taken = false;
            ll curr = 0;
            for(int i=0;i<33;i++){
                if(freq[i]>0){
                    taken = true;
                    curr = (curr+(long long)pow(2,i))%mod;
                    freq[i]--;
                }
            }
            if(!taken) break;
            result = (result+(curr*curr)%mod)%mod;
        }
        return result;
    }
};