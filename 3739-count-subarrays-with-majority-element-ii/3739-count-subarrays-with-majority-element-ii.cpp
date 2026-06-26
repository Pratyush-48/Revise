class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long result = 0;
        unordered_map<long long,long long>mp;
        long long curr = 0;
        long long tot = 0;
        mp[0] = 1;
        for(auto &it:nums){
            if(it==target){
                tot += mp[curr];
                curr++;
            }
            else{
                curr--;
                tot-=mp[curr];
            }
            mp[curr]++;
            result += tot;
        }
        return result;
    }
};