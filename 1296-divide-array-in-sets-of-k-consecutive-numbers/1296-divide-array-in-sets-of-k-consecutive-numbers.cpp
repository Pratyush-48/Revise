class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0) return false;
        unordered_map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==0) continue;
            for(int j=nums[i];j<(nums[i]+k);j++){
                if(mp.find(j)==mp.end() || mp[j]==0) return false;
                mp[j]--;
            }
        }
        return true;
    }
};