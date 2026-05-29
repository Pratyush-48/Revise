class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(auto &it:nums){
            int num = it;
            int new_num = 0;
            while(num){
                new_num += (num%10);
                num /= 10;
            }
            mini = min(mini,new_num);
        }
        return mini;
    }
};