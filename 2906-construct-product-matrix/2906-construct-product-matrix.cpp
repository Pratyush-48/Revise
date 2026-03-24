class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>>pre(n,vector<long long>(m,1));
        vector<vector<long long>>suff(n,vector<long long>(m,1));
        long long mod = 12345;
        long long pr = 1;
        long long suf = 1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                suff[i][j] = suf%mod;
                suf = (suf*grid[i][j])%mod;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre[i][j] = pr;
                pr = (pr*grid[i][j])%mod;
            }
        }
        vector<vector<int>>result(n,vector<int>(m,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result[i][j] = ((pre[i][j]*suff[i][j])%mod);
            }
        }
        return result;
    }
};