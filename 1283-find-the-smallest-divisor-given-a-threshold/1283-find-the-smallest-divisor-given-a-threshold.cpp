class Solution {
public:
    bool help(vector<int>&nums,int th,int num){
        int result = 0;
        for(auto &it:nums){
            result += ceil((double)it/num);
            if(result>th) return false;
        }
        return result<=th;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int l = 1;
        int r = maxi;
        int result = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(help(nums,threshold,mid)){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
};