class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0;
        long mul = 1;
        for(auto &it:nums){
            if(it==0){
                zero++;
                continue;
            }
            mul *= (long)it;
        }
        int n = nums.size();
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            if((nums[i]!=0 && zero==0)){
                result[i] = mul/nums[i];
            }
            else if(nums[i]==0 && zero==1){
                result[i] = mul;
            }
        }
        return result;
    }
};