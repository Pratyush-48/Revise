class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = k-1;
        int n = nums.size();
        if(k==1) return 0;
        int result = INT_MAX;
        while(j<n && i<n){
            if((j-i+1)==k){
                result = min(result,nums[j]-nums[i]);
                i++;
                j++;
            }
        }
        return result;
    }
};