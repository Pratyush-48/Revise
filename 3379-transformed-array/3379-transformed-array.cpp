class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                result[i]=nums[i];
            }
               else if(nums[i]>0){
                   int j = ((i+nums[i])%n);
                   result[i]=nums[j];
               }
            else{
              int steps = abs(nums[i]);
            int new_index = (i + n - abs(nums[i]) % n) % n;
            result[i] = nums[new_index];
            }
            
        }
        return result;
    }
};