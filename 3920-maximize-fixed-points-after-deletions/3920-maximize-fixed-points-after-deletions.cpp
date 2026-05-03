class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        vector<vector<int>>num_diff;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=i)
            num_diff.push_back({i-nums[i],nums[i]});
        }
        sort(num_diff.begin(),num_diff.end());
        vector<int>lis;
        for(auto &it:num_diff){
            int num = it[1];
            auto t = lower_bound(lis.begin(),lis.end(),num);
            if(t==lis.end()){
                lis.push_back(num);
            }
            else{
                *t = num;
            }
        }
        for(auto &it:lis){
            cout<<it<<" ";
        }
        return lis.size();
    }
};