class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int result = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]==nums[j] && nums[i]==nums[k]){
                        result = min(result,abs(i-j)+abs(j-k)+abs(k-i));
                    }
                }
            }
        }
        return result==INT_MAX?-1:result;
    }
};