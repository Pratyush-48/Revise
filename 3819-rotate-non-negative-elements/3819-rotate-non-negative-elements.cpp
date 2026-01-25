class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>idx;
        int n = nums.size();
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                idx.push_back(i);
            }
            else{
                result[i] = nums[i];
            }
        }
        int m = idx.size();
        if(m==0) return result;
        k%=m;
        for(int i=0;i<m;i++){
            int nidx = (i+k)%m;
            result[idx[i]] = nums[idx[nidx]];
        }
        return result;
    }
};