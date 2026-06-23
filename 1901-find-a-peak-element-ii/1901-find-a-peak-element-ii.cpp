class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            int i = -1;
            int j = -1;
            int maxi = INT_MIN;
            for(int k=0;k<m;k++){
                if(mat[k][mid]>maxi){
                    i = k;
                    j = mid;
                    maxi = mat[k][mid];
                }
            }
            int left = j>0?mat[i][mid-1]:-1;
            int right = j<n-1?mat[i][mid+1]:-1;
            if(maxi>left && maxi>right) return {i,j};
            else if(maxi<left) r = mid-1;
            else l = mid+1; 
        }
        return {-1,-1};
    }
};