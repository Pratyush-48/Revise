class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int n = intervals.size();
        for(int i=1;i<n;i++){
            int m = ans.size();
            if(ans[m-1][1]>=intervals[i][0]){
                ans[m-1][1]=max(ans[m-1][1],intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};