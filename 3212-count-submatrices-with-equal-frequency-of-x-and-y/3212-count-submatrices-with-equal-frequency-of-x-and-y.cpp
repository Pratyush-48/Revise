class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>x(n,vector<int>(m,0));
        vector<vector<int>>y(n,vector<int>(m,0));
        int result = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                x[i][j] = grid[i][j]=='X';
                y[i][j] = grid[i][j]=='Y';
                int prev_x = i>0?x[i-1][j]:0;
                int prev_y = i>0?y[i-1][j]:0;
                int r_x = j>0?x[i][j-1]:0;
                int r_y = j>0?y[i][j-1]:0;
                int dx = (i>0 && j>0)?x[i-1][j-1]:0;
                int dy = (i>0 && j>0)?y[i-1][j-1]:0;
                x[i][j] += (prev_x+r_x-dx);
                y[i][j] += (prev_y+r_y-dy);
                if(x[i][j]==y[i][j] && x[i][j]>0) result++;
            }
        }
        return result;
    }
};