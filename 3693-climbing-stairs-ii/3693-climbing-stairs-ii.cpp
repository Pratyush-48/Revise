class Solution {
public:
    int dp[100005];
    int recc(int currStep, int n, const vector<int>& costs) {
        if (currStep == n) return 0;
        if(dp[currStep]!=-1) return dp[currStep];
        int minCost = 1e9;
        for (int step = 1; step <= 3; ++step) {
            int nextStep = currStep + step;
            if (nextStep <= n) {
                int jumpCost = costs[nextStep - 1] + (step * step);
                minCost = min(minCost, jumpCost + recc(nextStep, n, costs));
            }
        }

        return dp[currStep]=minCost;
    }

    int climbStairs(int n, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return recc(0, n, costs);
    }
};