class Solution {
public:
    int m;
    int po(long long x, long n) {
        
        if(n == 0)
            return 1;
        if(n%2 == 0) {
            return po((x*x)%m, n/2);
        }
        return (x*po((x*x)%m, (n-1)/2))%m;
        
    }
    int inv(long long n,long mod){
        return po(n,mod-2)%m;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long mod = 1e9 + 7;
        m = 1e9 + 7;
        int n = nums.size();
        //vector<long long>diff(n,1);
        int sq = sqrt(n);
        unordered_map<int,vector<vector<int>>>q;
        for(auto &it:queries){
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];
            if(k<sq){
             q[k].push_back(it);
             continue;
            }
            for(int i=l;i<=r;i+=k){
                nums[i] = ((long long)nums[i]*v)%mod;
            }
        }
        for(auto &it:q){
            int k = it.first;
            vector<long long>diff(n,1);
            for(auto &a:it.second){
                int l = a[0];
                int r = a[1];
                int v = a[3];
                diff[l] = (diff[l]*v)%mod;
                int steps = (r-l)/k;
                int next = l + (steps+1)*k;
                if(next<n){
                    diff[next] = (diff[next]*inv(v,mod))%mod;
                }
            }
            for(int i=0;i<n;i++){
                if(i-k >= 0){
                    diff[i] = (diff[i]*diff[i-k])%mod;
                }
            }
            for(int i=0;i<n;i++){
                nums[i] = ((long long)nums[i]*diff[i])%mod;
            }
        }
        long long xo = 0;
        for(auto &it:nums){
            xo ^= it;
        }
        return xo;
    }
};