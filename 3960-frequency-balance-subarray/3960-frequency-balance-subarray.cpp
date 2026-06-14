class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int result = 1;
        for(int i=0;i<n;i++){
            unordered_map<int,int>curr_freq;
            unordered_map<int,int>two;
            for(int j=i;j<n;j++){
                int prev = curr_freq[nums[j]];
                curr_freq[nums[j]]++;
                if(prev != 0 && two.find(prev)!=two.end()){
                    two[prev]--;
                    if(two[prev]==0){
                        two.erase(prev);
                    }
                }
                two[curr_freq[nums[j]]]++;
                int mini = INT_MAX;
                int maxi = INT_MIN;
                if(curr_freq.size()==1){
                    result = max(result,j-i+1);
                }
                if(two.size()==2){
                    for(auto &it:two){
                        mini = min(mini,it.first);
                        maxi = max(maxi,it.first);
                    }
                    if((maxi == (mini*2))){
                        result = max(result,j-i+1);
                    }
                }
            }
        }
        return result;
    }
};