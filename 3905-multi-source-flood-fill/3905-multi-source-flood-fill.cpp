class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>grid(n,vector<int>(m,0));
        vector<vector<int>>time(n,vector<int>(m,0));
        queue<vector<int>>q;
        for(auto &it : sources) {
            grid[it[0]][it[1]] = max(grid[it[0]][it[1]], it[2]);
        }
        for(auto &it:sources){
            q.push(it);
        }
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        int timee = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto vec = q.front();
                q.pop();
                int r = vec[0];
                int c = vec[1];
                int co = vec[2];
                if(co<grid[r][c]) continue;
                if(time[r][c]==timee|| grid[r][c]==0){
                    grid[r][c] = max(grid[r][c],co);
                    time[r][c] = timee;
                }
                for(auto &it:dir){
                    int new_r = it[0]+r;
                    int new_c = it[1]+c;
                    if(new_r>=0 && new_r<n && new_c>=0 && new_c<m && 
                      (grid[new_r][new_c]==0 || 
                      (grid[new_r][new_c] < co && time[new_r][new_c]==timee+1))){
                        grid[new_r][new_c] = co;
                        time[new_r][new_c] = timee+1;
                        q.push({new_r,new_c,co});
                    }
                }
            }
            timee++;
        }
        return grid;
    }
};