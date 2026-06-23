class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l  = 0;
        int r = n-1;
        while(l<r){
            int mid = (l+r)/2;
            int right = (r-mid);
            bool odd = right%2;
            if(mid<n && nums[mid]==nums[mid+1]){
                if(odd){
                    r = mid-1;
                }
                else l = mid+2;
            }
            else{
                if(mid>0 && nums[mid]!=nums[mid-1]) return nums[mid];
                if(odd){
                    l = mid+1;
                }
                else{
                    r = mid-2;
                }
            }
        }
        return nums[r];
    }
};