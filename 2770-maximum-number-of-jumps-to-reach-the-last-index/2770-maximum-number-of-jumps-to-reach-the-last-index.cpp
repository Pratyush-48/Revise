class Solution {
    int f(int i, vector<int>& a, int t, vector<int>& dp) {
        int n = a.size();
        if (i == n - 1) return 0;
        if (dp[i] != -1) return dp[i];
        
        int mx = -1e9;
        for (int j = i + 1; j < n; ++j) {
            if (abs(a[i] - a[j]) <= t) {
                int nx = f(j, a, t, dp);
                if (nx != -1e9) mx = max(mx, 1 + nx);
            }
        }
        return dp[i] = mx;
    }

public:
    int maximumJumps(vector<int>& a, int t) {
        vector<int> dp(a.size(), -1);
        int r = f(0, a, t, dp);
        return r < 0 ? -1 : r;
    }
};