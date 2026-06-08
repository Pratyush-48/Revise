class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans(n,-1);
        int start = 0;
        int end = n-1;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                ans[start]=nums[i];
                start++;
            }
        }
        for(int j=n-1;j>=0;j--){
            if(nums[j]>pivot){
                ans[end]=nums[j];
                end--;
            }
        }
        for(int i=start;i<=end;i++){
            ans[i]=pivot;
        }
        return ans;
    }
};