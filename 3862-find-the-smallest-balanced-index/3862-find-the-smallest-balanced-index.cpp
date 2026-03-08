class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int result = -1;
        long long int total = 0;
        for(auto &it:nums){
            total += it;
        }
        int n = nums.size();
        vector<long long int>mult(n,1);
        long long int cap = total+1;
        long long int curr_prod = 1;
        for(int i=n-1;i>=0;i--){
            mult[i] = curr_prod;
            if(curr_prod>cap){
                curr_prod = cap+1;
            }
            else{
                if(nums[i] > (cap/curr_prod)){
                    curr_prod = cap+1;
                }
                else{
                    curr_prod *= nums[i];
                }
            }
        }
        long long int curr_sum = 0;
        for(int i=0;i<n;i++){
            if(mult[i]==curr_sum) return i;
            curr_sum = curr_sum + (long long)nums[i];
        }
        return -1;
    }
};