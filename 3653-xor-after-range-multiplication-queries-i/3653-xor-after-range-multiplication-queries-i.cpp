class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int mod = 1e9 + 7;
        for(auto &it:queries){
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];  
            for(int i=l;i<=r;i+=k){
                nums[i] = ((long long)nums[i]*v)%mod;
            }
        }
        int xorr = 0;
        for(auto &it:nums){
            xorr ^= it;
        }
        return xorr;
    }
};