class Solution {
public:
    int rev(int num){
        string m = to_string(num);
        int res = 0;
        while(!m.empty()){
            char b = m.back();
            m.pop_back();
            res = res * 10;
            res += (b-'0');
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int result = INT_MAX;
        for(int i=0;i<n;i++){
            int rev_num = rev(nums[i]);
            if(mp.find(nums[i])!=mp.end()){
                result = min(result,i-mp[nums[i]]);
            }
            mp[rev_num] = i;
        }
        return result==INT_MAX?-1:result;
    }
};