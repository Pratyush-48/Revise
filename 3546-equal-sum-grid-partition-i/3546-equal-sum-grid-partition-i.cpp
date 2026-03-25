class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<ll>row_sum(m,0);
        vector<ll>col_sum(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row_sum[i] += grid[i][j];
                col_sum[j] += grid[i][j];
            }
        }
        ll total_row = accumulate(row_sum.begin(),row_sum.end(),0LL);
        ll total_col = accumulate(col_sum.begin(),col_sum.end(),0LL);
        ll row = 0;
        ll col = 0;
        for(int i=0;i<m;i++){
            row += row_sum[i];
            total_row -= row_sum[i];
            if(row==total_row) return true;
        }
        for(int i=0;i<n;i++){
            col += col_sum[i];
            total_col -= col_sum[i];
            if(col==total_col) return true;
        }
        return false;
    }
};