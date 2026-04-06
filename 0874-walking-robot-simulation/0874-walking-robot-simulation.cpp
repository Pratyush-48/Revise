class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<vector<int>>obs(obstacles.begin(),obstacles.end());
        int x = 0;
        int y = 0;
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        int idx = 0;
        int result = 0;
        for(auto &it:commands){
            if(it==-2){
                idx = (idx-1+4)%4;
            }
            else if(it==-1){
                idx = (idx+1)%4;
            }
            else{
                int k = it;
                while(k--){
                    int new_i = x+dir[idx][0];
                    int new_j = y+dir[idx][1];
                    if(obs.find({new_i,new_j})!=obs.end()) break;
                    x = new_i;
                    y = new_j;
                    result = max(result,x*x + y*y);
                }
            }
        }
        return result;
    }
};