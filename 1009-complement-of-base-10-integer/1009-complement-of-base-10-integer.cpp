class Solution {
public:
    int bitwiseComplement(int n) {
        int result = 0;
        vector<int>nums;
        while(n>0){
            int num = n%2;
            num = (1+num)%2;
            nums.push_back(num);
            n /= 2;
        }
        reverse(nums.begin(),nums.end());
        for(auto &it:nums){
            result = result<<1;
            result |= it;
        }
        return result;
    }
};