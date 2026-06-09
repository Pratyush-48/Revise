class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto &it:nums){
            maxi = max(maxi,it);
            mini = min(mini,it);
        }
        long long result = (long long)k*(maxi-mini);
        return result;
    }
};