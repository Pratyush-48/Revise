class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    bool found = false;
                    for(int k=0;k<n;k++){
                        if(k==j) continue;
                        if(mat[i][k]!=0){
                            found = true;
                            break;
                        }
                    }
                    if(found) continue;
                    for(int k=0;k<m;k++){
                        if(k==i) continue;
                        if(mat[k][j]!=0){
                            found = true;
                            break;
                        }
                    }
                    if(!found) result++;
                }
            }
        }
        return result;
    }
};