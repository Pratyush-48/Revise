class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            int odd = 0;
            int even = 0;
            for(int j=i;j<n;j++){
                if(mp.find(nums[j])==mp.end()){
                if(nums[j]%2){
                    odd++;
                }
                else{
                    even++;
                }
                }
                mp[nums[j]]++;
                if(odd==even){
                    result = max(result,j-i+1);
                }
            }
        }
        return result;
    }
};