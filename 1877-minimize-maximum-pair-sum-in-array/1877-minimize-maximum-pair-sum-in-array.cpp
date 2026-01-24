class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        sort(nums.begin(),nums.end());
        int result = 0;
        while(left<right){
            int sum = nums[left++]+nums[right--];
            result = max(result,sum);
        }
        return result;
    }
};