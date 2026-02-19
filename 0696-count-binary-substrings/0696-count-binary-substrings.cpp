class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int i = 0;
        vector<int>nums;
        long result = 0;
        while(i<n){
            int left = i;
            if(s[i]=='0'){
                while(i<n && s[i]=='0'){
                    i++;
                }
            }
            else{
                while(i<n && s[i]=='1'){
                    i++;
                }
            }
            nums.push_back(i-left);
        }
        int m = nums.size();
        for(int j=1;j<m;j++){
            result += min(nums[j],nums[j-1]);
        }
        return result;
    }
};