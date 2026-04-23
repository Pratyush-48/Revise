class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,pair<long long,int>> prefix;
        int n = nums.size();
        vector<long long>result(n,0);
        for(int i=1;i<n;i++){
            prefix[nums[i-1]].first+=(i-1);
            prefix[nums[i-1]].second++;
            if(prefix.find(nums[i])!=prefix.end()){
                long long ind_sum = prefix[nums[i]].first;
                long long count = prefix[nums[i]].second;
                result[i] = abs((i*count)-ind_sum);
            }
        }
        unordered_map<int,pair<long long,int>>suffix;
        for(int i=n-2;i>=0;i--){
            suffix[nums[i+1]].first+=(i+1);
            suffix[nums[i+1]].second++;
            if(suffix.find(nums[i])!=suffix.end()){
                long long ind_sum = suffix[nums[i]].first;
                long long count = suffix[nums[i]].second;
                result[i] += abs(ind_sum-(i*count));
            }
        }
        return result;
    }
};