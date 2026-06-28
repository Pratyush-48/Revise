class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int result = 1;
        unordered_map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        if (mp.count(1)) {
            int ones = mp[1];
            if (ones % 2 == 0) ones -= 1; // Sequence length must be odd
            result = max(result, ones);
        }
        int maxi = *max_element(nums.begin(),nums.end());
        for(auto &it:nums){
            long numm = it;
            long num = 1;
            int curr = 0;
            if(it==1) continue;
            for(int i=1;i<=32;i++){
                num = num*numm;
                numm = num;
                if(num>maxi) break;
                if(mp[num]==1){
                    curr+=1;
                    break;
                }
                if(mp[num]>=2){
                    curr+=2;
                }
                else{ 
                    break;
                }
            }
            if(curr%2 == 0){
                curr-=1;
            }
            result = max(result,curr);
        }
        return result;
    }
};