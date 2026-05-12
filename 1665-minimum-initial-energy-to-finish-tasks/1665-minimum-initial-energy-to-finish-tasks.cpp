class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
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
        return start;
    }
};