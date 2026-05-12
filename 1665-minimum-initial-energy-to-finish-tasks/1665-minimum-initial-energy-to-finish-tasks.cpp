class Solution {
public:
    bool bs(vector<vector<int>>&tasks,int mid,int n){
        long start = tasks[0][1];
        long curr = start;
        for(int i=0;i<n;i++){
            if(curr>=tasks[i][1]){
                curr -= tasks[i][0];
            }
            else{
                long diff = abs(curr-tasks[i][1]);
                curr += diff;
                start += diff;
                curr -= tasks[i][0];
            }
        }
        return start<=mid;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        int right = 1e9;
        int left = 1;
        int result = -1;
        while(left<=right){
            int mid = (left+right)/2;
            if(bs(tasks,mid,n)){
                result = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return result;
    }
};