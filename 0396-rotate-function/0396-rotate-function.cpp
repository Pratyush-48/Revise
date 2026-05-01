class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int sum = 0;
        int f  = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            f += (i*nums[i]);
        }
        result = f;
        for(int i=0;i<n;i++){
            int newf = f + sum - n*nums[n-i-1];
            f = newf;
            result = max(result,f);
        }
        return result;
    }
};